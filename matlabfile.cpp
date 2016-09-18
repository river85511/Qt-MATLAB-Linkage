#include "matlabfile.h"

MatlabFile::MatlabFile(QString _lengthUnit): timeInterval(0.01), lengthUnit(_lengthUnit)
{
    qDebug() << "MatlabFile Created";
}

MatlabFile::~MatlabFile()
{
    qDebug() << "MatlabFile Deleted";
}

void MatlabFile::findAllJoints()
{
    foreach(QGraphicsItem* item, totalItemsList){
        if(typeid(*item) == typeid(RevolutionJoint))
            RJointList.push_front(static_cast<RevolutionJoint *>(item));
        else if(typeid(*item) == typeid(PrismaticJoint))
            PJointList.push_front(static_cast<PrismaticJoint *>(item));
    }
//    qDebug() << "ALL JOINTS HAVE BEEN FOUND!";
    return;
}

bool MatlabFile::checkIsAlreadyCounted(int _id)
{
        for(QList<int>::iterator i = idList.begin(); i!=idList.end(); i++){
            if((*i) == _id ){
                return true;
            }
        }

        idList.push_back(_id);
        return false;
}

void MatlabFile::findAllRigidBody()
{
    //Include GROUND
    foreach(QGraphicsItem* item, totalItemsList){
        if(typeid(*item) == typeid(NewBar)){
            if(static_cast<NewBar *>(item)->id == 0){
                addToBarList(static_cast<NewBar *>(item));
                break;
            }
        }
    }

        //Include other BAR and SLIDE
    QList<RevolutionJoint *>::iterator i;
        for(i = RJointList.begin(); i < RJointList.end(); i++){
            if( typeid(*(*i)->pinA->parentItem()) == typeid(NewBar))
                addToBarList(static_cast<NewBar *>((*i)->pinA->parentItem()));
            else if(typeid(*(*i)->pinA->parentItem()) == typeid(Slide))
                addToSlideList(static_cast<Slide *>((*i)->pinA->parentItem()));


            if( typeid(*(*i)->pinB->parentItem()) == typeid(NewBar))
                addToBarList(static_cast<NewBar *>((*i)->pinB->parentItem()));
            else if(typeid(*(*i)->pinB->parentItem()) == typeid(Slide))
                addToSlideList(static_cast<Slide *>((*i)->pinB->parentItem()));
        }

        sortIdList();
}

void MatlabFile::addToBarList(NewBar *bar)
{
    int id  = bar->id;
    if(!checkIsAlreadyCounted(id))
        totalBarList.push_back(bar);
}

void MatlabFile::addToSlideList(Slide *slide)
{
    int id = slide->id;
    if(!checkIsAlreadyCounted(id))
        totalSlideList.push_back(slide);
}

void MatlabFile::sortIdList()
{
    std::sort(idList.begin(),idList.end());
}

void MatlabFile::genFile()
{
    findAllJoints();
    findAllRigidBody();

    genMainFile();
    genFunctionFile();
}

void MatlabFile::genMainFile()
{
    QFile data("main.m");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&data);

        genMainFileOpening(out);
            genInitialCondition(out);
                genMainFileCalculationBeginning(out);
                    genMainFileDisplacement(out);
                    genMainFileVelocity(out);
                    genMainFileAcceleration(out);
                genMainFileCalculationEnding(out);
                genDisplacementPlot(out);
                genVelocityPlot(out);
                genAccelerationPlot(out);
                genDisplacementArray(out);
        genMainFileEnding(out);
    }

}

void MatlabFile::genMainFileOpening(QTextStream &out)
{
//    qDebug() << "genMainFileOpening";
        out << QString("clc; clear;") << "\n" << flush;
        out << QString("T_Int = 0:%1:%2").arg(timeInterval).arg(totalTime) << '\n' << '\n' << flush;
}

void MatlabFile::genInitialCondition(QTextStream &out)
{
//    qDebug() << "genInitialCondition";
        out << QString("global T") << '\t';
        for(QList<NewBar *>::iterator i = totalBarList.begin(); i != totalBarList.end(); i++){
            if((*i)->id != 0)
                out << QString("L%1").arg((*i)->id) << "\t";
        }
        out << "\n" << flush;

        for(QList<NewBar *>::iterator i = totalBarList.begin(); i<totalBarList.end(); i++){
            if((*i)->id != 0)
                out << QString("L%1 = %2;").arg((*i)->id).arg((*i)->getRectWidth()) << "\n";
        }

        out << QString("Xinit = [");

        int totalRigidBody = totalBarList.size() + totalSlideList.size();
        int toBeFound = 0;
        int i = 0;

        while(toBeFound != totalRigidBody){
            bool found = false;

            foreach(NewBar* bar, totalBarList){
                if(bar->id == i){
//                    qDebug() <<bar->id;
                    out << QString("%1 %2 %3 ").arg(bar->getRectMassCenter().x()).
                                                arg(bar->getRectMassCenter().y()).
                                                arg(bar->getRectAngleRadians());
                    found = true;
                    toBeFound++;
                    break;
                }
            }

            if(!found){
                foreach(Slide* slide, totalSlideList){
                    if(slide->id == i){
//                        qDebug() << slide->id;
                        out << QString("%1 %2 %3 ").arg(slide->getRectMassCenter().x()).
                                                    arg(slide->getRectMassCenter().y()).
                                                    arg(slide->getRectAngleRadians());
                        toBeFound++;
                        break;
                    }
                }
            }

            i++;
        }

        out << QString("];") << flush;
}

void MatlabFile::genMainFileCalculationBeginning(QTextStream &out)
{
//    qDebug() << "genMainFileCalculationBeginning";
        out << "\n" << "\n" << QString("for Iter = 1:length(T_Int);") << "\n" << flush;
        out << QString("T = T_Int(Iter)") << "\n" << flush;
}

void MatlabFile::genMainFileDisplacement(QTextStream &out)
{
//    qDebug() << "genMainFileDisplacement";
        out << QString("[Xtemp, fval] = fsolve(@constrEq4bar,Xinit);") << "\n" << flush;
        out << QString("X(:,Iter) = Xtemp;") << "\n" << flush;
}

void MatlabFile::genMainFileVelocity(QTextStream &out)
{
//    qDebug() << "genMainFileVelocity";
    out << "\n" << flush;
    for(int i = 0; i<idList.size(); i++){
        out << QString("phi%1 = Xtemp(%2); ").arg(idList[i]).arg(i*3+3);
    }
    out << "\n" << flush;

    foreach(PrismaticJoint* pJoint, PJointList){

        int slideId = pJoint->slide->id;
            QList<int>::iterator iter = idList.begin();
            for(int i = 0; iter < idList.end(); iter++, i++){
                if((*iter) == slideId){
                        out << QString("x%1 = Xtemp(%2); y%1 = Xtemp(%3);").arg(slideId).arg(i*3+1).arg(i*3+2) << "\n" << flush;
                }
            }

        int pJointConnectingId = pJoint->pJointConnectingItem->id;
            iter = idList.begin();
            for(int i = 0; iter < idList.end(); iter++, i++){
                if((*iter) == pJointConnectingId){
                        out << QString("x%1 = Xtemp(%2); y%1 = Xtemp(%3);").arg(pJointConnectingId).arg(i*3+1).arg(i*3+2) << "\n" << flush;
                }
            }
    }

    out << getJaco4BarStr() << QString(";") << "\n" << flush;

    foreach(NewBar* bar, totalBarList){
        if(bar->isDrivingLink == true){
            out << QString("Beta=[0 0 0 0 0 0 0 0 0 0 0 ((%1)+(%2)*T)]';").arg(bar->getAngularVel()).arg(bar->getAngularAcc()) << "\n" << flush;
            break;
        }
    }
    out << QString("Vtemp = JacoMatrix") << QString("\\") << QString("Beta;") << "\n" << flush;
    out << QString("V(:,Iter) = Vtemp;") << "\n" << flush;
}

void MatlabFile::genMainFileAcceleration(QTextStream &out)
{
//    qDebug() << "genMainFileAcceleration";
    out << "\n" << flush;
    for(int i = 0; i<idList.size(); i++){
        out << QString("dphi%1 = Vtemp(%2); ").arg(idList[i]).arg(i*3+3);
    }
    out << "\n" << flush;

    foreach(PrismaticJoint* pJoint, PJointList){
        int slideId = pJoint->slide->id;
            QList<int>::iterator iter = idList.begin();
            for(int i = 0; iter < idList.end(); iter++, i++){
                if((*iter) == slideId){
                        out << QString("dx%1 = Vtemp(%2); dy%1 = Vtemp(%3);").arg(slideId).arg(i*3+1).arg(i*3+2) << "\n" << flush;
                }
            }

        int pJointConnectingId = pJoint->pJointConnectingItem->id;
            iter = idList.begin();
            for(int i = 0; iter < idList.end(); iter++, i++){
                if((*iter) == pJointConnectingId){
                        out << QString("dx%1 = Vtemp(%2); dy%1 = Vtemp(%3);").arg(pJointConnectingId).arg(i*3+1).arg(i*3+2) << "\n" << flush;
                }
            }
    }

    out << getGamma4BarStr() << QString(";") << "\n" << flush;
    out << QString("Atemp = JacoMatrix") << QString("\\") << QString("Gamma") << QString(";") << "\n" << flush;
    out << QString("A(:,Iter)=Atemp;") << "\n" << flush;
}

QString MatlabFile::getJaco4BarStr()
{
    QString jaco4BarStr;
    jaco4BarStr += QString("JacoMatrix = Jaco4bar(");

    QString phiStr;
    for(int i =0; i<idList.size(); i++){
        phiStr += QString("phi%1,").arg(idList[i]);
    }

    if(PJointList.size() == 0){
        phiStr.chop(1);
        jaco4BarStr += (phiStr + QString(")"));
    }else{
        QString xyStr;
        foreach(PrismaticJoint* pJoint, PJointList){
            int slideId = pJoint->slide->id;
                xyStr += QString("x%1,y%1,").arg(slideId);

            int pJointConnectingId = pJoint->pJointConnectingItem->id;
                xyStr +=  QString("x%1,y%1,").arg(pJointConnectingId);
        }
        xyStr.chop(1);
        jaco4BarStr += (phiStr +  xyStr + QString(")"));
    }

    return jaco4BarStr;
}

QString MatlabFile::getGamma4BarStr()
{
    QString gamma4BarStr;
    gamma4BarStr += QString("Gamma = Gamma4bar(");

    QString phiStr;
    for(int i =0; i<idList.size(); i++){
        phiStr += QString("phi%1,").arg(idList[i]);
    }


        QString dphiStr;
        for(int i =0; i<idList.size(); i++){
            dphiStr += QString("dphi%1,").arg(idList[i]);
        }

    if(PJointList.size() == 0){
        dphiStr.chop(1);
        gamma4BarStr += ( phiStr + dphiStr + QString(")"));
    }else{
        QString xyStr;
        foreach(PrismaticJoint* pJoint, PJointList){
            int slideId = pJoint->slide->id;
                xyStr += QString("dx%1,dy%1,x%1,y%1,").arg(slideId);

            int pJointConnectingId = pJoint->pJointConnectingItem->id;
                xyStr += QString("dx%1,dy%1,x%1,y%1,").arg(pJointConnectingId);
        }
        xyStr.chop(1);
        gamma4BarStr += (phiStr + dphiStr + xyStr + QString(")"));
    }
    return gamma4BarStr;
}

void MatlabFile::genMainFileCalculationEnding(QTextStream &out)
{
//    qDebug() << "genMainFileCalculationEnding";
        out << "\n" << QString("if Iter == 1") << "\n" << flush;
        out << "\t" <<QString("Xinit = X(:,Iter);") << "\n" << flush;
        out << QString("else") << "\n" << flush;
        out << "\t" << QString("Xinit = X(:,Iter) + (X(:,Iter) - X(:,Iter-1));") << "\n" << flush;
        out << QString("end") << "\n" << QString("end") << "\n" << flush;
}

void MatlabFile::genDisplacementPlot(QTextStream &out)
{
    out << "\n" << flush;
    for(int i =1; i < idList.size(); i++){
        out << QString("figure('name','Diplacemnet For RB%1')").arg(idList.at(i)) << "\n" << flush;
        out << QString("for i = %1:%2").arg(i*3+1).arg(i*3+3) << "\n" << flush;
            out << QString("\tsubplot(3,1,i-%1)").arg(i*3) << "\n" << flush;
            out << QString("\tplot(T_Int,X(i,:))") << "\n" << flush;
            out << QString("\tset(gca,'xtick',[], 'FontSize', 5)") << "\n" << flush;
            out << QString("\txlabel('t(s)','FontSize',10)") << "\n" << flush;
            out << QString("\tswitch i") << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+1) << "\n" << flush;
                    out << QString("\t\t\tylabel('dx%1(%2)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+2) << "\n" << flush;
                    out << QString("\t\t\tylabel('dy%1(%2)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+3) << "\n" << flush;
                    out << QString("\t\t\tylabel('dtheta%1(rad)','FontSize',10)").arg(idList.at(i)) << "\n" << flush;
            out << QString("\tend") << "\n" << flush;
        out << QString("end") << "\n" << flush;
        out << QString("set(gca,'xtickMode', 'auto')") << "\n" << flush;
        out << QString("print('RB%1 Displacement','-dpng')").arg(idList.at(i)) << flush;
        out << QString("\n") << flush;
    }

}

void MatlabFile::genVelocityPlot(QTextStream &out)
{
    out << "\n" << flush;
    for(int i =1; i < idList.size(); i++){
        out << QString("figure('name','Velocity For RB%1')").arg(idList.at(i)) << "\n" << flush;
        out << QString("for i = %1:%2").arg(i*3+1).arg(i*3+3) << "\n" << flush;
            out << QString("\tsubplot(3,1,i-%1)").arg(i*3) << "\n" << flush;
            out << QString("\tplot(T_Int,V(i,:))") << "\n" << flush;
            out << QString("\tset(gca,'xtick',[], 'FontSize', 5)") << "\n" << flush;
            out << QString("\txlabel('t(s)','FontSize',10)") << "\n" << flush;
            out << QString("\tswitch i") << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+1) << "\n" << flush;
                    out << QString("\t\t\tylabel('Vx%1(%2/s)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+2) << "\n" << flush;
                    out << QString("\t\t\tylabel('Vy%1(%2/s)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+3) << "\n" << flush;
                    out << QString("\t\t\tylabel('Vtheta%1(rad/s)','FontSize',10)").arg(idList.at(i)) << "\n" << flush;
            out << QString("\tend") << "\n" << flush;
        out << QString("end") << "\n" << flush;
        out << QString("set(gca,'xtickMode', 'auto')") << "\n" << flush;
        out << QString("print('RB%1 Velocity','-dpng')").arg(idList.at(i)) << flush;
        out << QString("\n") << flush;
    }
}

void MatlabFile::genAccelerationPlot(QTextStream &out)
{
    out << "\n" << flush;
    out << "\n" << flush;
    for(int i =1; i < idList.size(); i++){
        out << QString("figure('name','Acceleration For RB%1')").arg(idList.at(i)) << "\n" << flush;
        out << QString("for i = %1:%2").arg(i*3+1).arg(i*3+3) << "\n" << flush;
            out << QString("\tsubplot(3,1,i-%1)").arg(i*3) << "\n" << flush;
            out << QString("\tplot(T_Int,A(i,:))") << "\n" << flush;
            out << QString("\tset(gca,'xtick',[], 'FontSize', 5)") << "\n" << flush;
            out << QString("\txlabel('t(s)','FontSize',10)") << "\n" << flush;
            out << QString("\tswitch i") << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+1) << "\n" << flush;
                    out << QString("\t\t\tylabel('Ax%1(%2/s^2)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+2) << "\n" << flush;
                    out << QString("\t\t\tylabel('Ay%1(%2/s^2)','FontSize',10)").arg(idList.at(i)).arg(lengthUnit) << "\n" << flush;
                out << QString("\t\tcase %1").arg(i*3+3) << "\n" << flush;
                    out << QString("\t\t\tylabel('Atheta%1(rad/s^2)','FontSize',10)").arg(idList.at(i)) << "\n" << flush;
            out << QString("\tend") << "\n" << flush;
        out << QString("end") << "\n" << flush;
        out << QString("set(gca,'xtickMode', 'auto')") << "\n" << flush;
        out << QString("print('RB%1 Acceleration','-dpng')").arg(idList.at(i)) << flush;
        out << QString("\n") << flush;
    }
}

void MatlabFile::genDisplacementArray(QTextStream &out)
{
    out << "\n" << flush;
    out << QString("[m n] = size(X);") << "\n" << flush;
    out << QString("str = 'animation.txt';") << "\n" << flush;
    out << QString("fin = fopen(str,'wt');") << "\n" << flush;
    out << QString("for i = 1:m") << "\n" << flush;
    out << QString("    for j =1:n") << "\n" << flush;
    out << QString("    fprintf(fin,'%d\t',X(i,j));") << "\n" << flush;
    out << QString("    end") << "\n" << flush;
    out << QString("fprintf(fin,'\\n');") << "\n" << flush;
    out << QString("end") << "\n" << flush;
    out << QString("fclose(fin);") << "\n" << flush;
}

void MatlabFile::genMainFileEnding(QTextStream &out)
{
//    qDebug() << "genMainFileEnding";
}

void MatlabFile::genFunctionFile()
{

    QFile constrEq4bar("constrEq4bar.m");
    if (constrEq4bar.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&constrEq4bar);

        genConstrEqnOpening(out);
            genConstrEqn(out);
            genDrivingEqn(out);
        genFConstrEqnEnding(out);
    }

    QFile Jaco4bar("Jaco4bar.m");
    if (Jaco4bar.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&Jaco4bar);
        genJaco4barOpening(out);
            genJaco4bar(out);
            genJaco4barDriving(out);
        genJaco4barEnding(out);
    }

    QFile Gamma4bar("Gamma4bar.m");
    if (Gamma4bar.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&Gamma4bar);
        genGamma4barOpening(out);
            genGamma4bar(out);
            genGamma4barDriving(out);
        genGamma4barEnding(out);
    }
}

void MatlabFile::genConstrEqnOpening(QTextStream &out)
{
//    qDebug() << "genConstrEqnOpening";
        out << QString("function F=constrEq4bar(X)") << '\n' << '\n' << flush;
        out << QString("global T") << "\t";
        for(QList<NewBar *>::iterator i = totalBarList.begin(); i<totalBarList.end(); i++){
            if((*i)->id != 0)
                out << QString("L%1").arg((*i)->id) << "\t";
        }
        out << "\n" << "\n" << flush;

        int totalRigidBody = totalBarList.size() + totalSlideList.size();
        int toBeFound = 0;
        int i = 0;

        while(toBeFound != totalRigidBody){
            bool found = false;

            foreach(NewBar* bar, totalBarList){
                if(bar->id == i){
                    out << QString("x%1=X(%2); y%1=X(%3); phi%1=X(%4);").arg(bar->id).
                                                                         arg(toBeFound*3+1).
                                                                         arg(toBeFound*3+2).
                                                                         arg(toBeFound*3+3) << '\n' << flush;
                    found = true;
                    toBeFound++;
                    emit rigidBodyID(bar->id);
                    break;
                }
            }

            if(!found){
                foreach(Slide* slide, totalSlideList){
                    if(slide->id == i){
                        out << QString("x%1=X(%2); y%1=X(%3); phi%1=X(%4);").arg(slide->id).
                                                                             arg(toBeFound*3+1).
                                                                             arg(toBeFound*3+2).
                                                                             arg(toBeFound*3+3) << '\n' << flush;
                        toBeFound++;
                        emit rigidBodyID(slide->id);
                        break;
                    }
                }
            }

            i++;
        }

        out << "\n" << flush;
        out << QString("F = [") << '\n'<< flush;
}

void MatlabFile::genConstrEqn(QTextStream &out)
{
//    qDebug() << "genConstrEqn";

    //Include GROUND
    foreach(NewBar* bar, totalBarList){
        if(bar->id == 0){
            out << QString("(x0 - 0);")   << '\n'
                << QString("(y0 - 0);")   << '\n'
                << QString("(phi0 - 0);") << '\n' << flush;
            break;
        }
    }

    foreach(RevolutionJoint* rJoint, RJointList){

        QString str_x;
        QString str_y;

        if( typeid(*rJoint->pinA->parentItem()) == typeid(NewBar) ){

            int id = static_cast<NewBar *>(rJoint->pinA->parentItem())->id ;

            if(rJoint->pinA->name == QString("left"))
            {
                    str_x += QString("( x%1 - 0.5*L%1 * cos(phi%1) )").arg(id);
                    str_y += QString("( y%1 - 0.5*L%1 * sin(phi%1) )").arg(id);
            }
            else if(rJoint->pinA->name == QString("right"))
            {
                    str_x += QString("( x%1 + 0.5*L%1 * cos(phi%1) )").arg(id);
                    str_y += QString("( y%1 + 0.5*L%1 * sin(phi%1) )").arg(id);
            }

        }else if( typeid(*rJoint->pinA->parentItem()) == typeid(Slide) ){

            int id = static_cast<Slide *>(rJoint->pinA->parentItem())->id ;

            str_x += QString("( x%1 )").arg(id);
            str_y += QString("( y%1 )").arg(id);

        }else if( typeid(*rJoint->pinA->parentItem()) == typeid(Anchor) ){

            double x = static_cast<Anchor *>(rJoint->pinA->parentItem())->getAnchorMassCenter().x();
            double y = static_cast<Anchor *>(rJoint->pinA->parentItem())->getAnchorMassCenter().y();

            str_x += QString("( x0 + (%1) )").arg(x);
            str_y += QString("( y0 + (%1) )").arg(y);
        }

        str_x += QString(" - ");
        str_y += QString(" - ");

        if( typeid(*rJoint->pinB->parentItem()) == typeid(NewBar) ){

            int id = static_cast<NewBar *>(rJoint->pinB->parentItem())->id ;

            if(rJoint->pinB->name == QString("left"))
            {
                str_x += QString("( x%1 - 0.5*L%1 * cos(phi%1) )").arg(id);
                str_y += QString("( y%1 - 0.5*L%1 * sin(phi%1) )").arg(id);
            }
            else if(rJoint->pinB->name == QString("right"))
            {
                str_x +=  QString("( x%1 + 0.5*L%1 * cos(phi%1) )").arg(id);
                str_y +=  QString("( y%1 + 0.5*L%1 * sin(phi%1) )").arg(id);
            }

        }else if( typeid(*rJoint->pinB->parentItem()) == typeid(Slide) ){

            int id = static_cast<Slide *>(rJoint->pinB->parentItem())->id ;

            str_x += QString("( x%1 )").arg(id);
            str_y += QString("( y%1 )").arg(id);

        }else if( typeid(*rJoint->pinB->parentItem()) == typeid(Anchor) ){

            double x = static_cast<Anchor *>(rJoint->pinB->parentItem())->getAnchorMassCenter().x();
            double y = static_cast<Anchor *>(rJoint->pinB->parentItem())->getAnchorMassCenter().y();

            str_x += QString("( x0 + (%1) )").arg(x);
            str_y += QString("( y0 + (%1) )").arg(y);
        }

        str_x += QString(";");
        str_y += QString(";");

        out << str_x << '\n' << flush;
        out << str_y << '\n' << flush;

    }

    foreach(PrismaticJoint* pJoint, PJointList){

        QString xTranslationStr;
        QString yTranslationStr;
        QString translationStr;
        QString angleStr;

        //Translation
        QString slideVerticalVectorX = QString("( -sin(phi%1)*(1) ))").arg(pJoint->slide->id);
        QString slideVerticalVectorY = QString("(  cos(phi%1)*(1) ))").arg(pJoint->slide->id);

        QString slideHorizontalVectorX = QString("( (( x%1 + (cos(phi%1)*(%2) - sin(phi%1)*(%3)) ) - ( x%4 + (cos(phi%4)*(1)) )  )").
                                                                        arg(pJoint->pJointConnectingItem->id).
                                                                        arg(pJoint->getLocalVectorToTranslationAxis().x()).
                                                                        arg(pJoint->getLocalVectorToTranslationAxis().y()).
                                                                        arg(pJoint->slide->id);
        QString slideHorizontalVectorY = QString("( (( y%1 + (sin(phi%1)*(%2) + cos(phi%1)*(%3)) ) - ( y%4 + (sin(phi%4)*(1)) ) )").
                                                                        arg(pJoint->pJointConnectingItem->id).
                                                                        arg(pJoint->getLocalVectorToTranslationAxis().x()).
                                                                        arg(pJoint->getLocalVectorToTranslationAxis().y()).
                                                                        arg(pJoint->slide->id);
        xTranslationStr += (slideHorizontalVectorX + QString("*") + slideVerticalVectorX);
        yTranslationStr += (slideHorizontalVectorY + QString("*") + slideVerticalVectorY);
        translationStr += (xTranslationStr + QString(" + ") + yTranslationStr) + QString(";");

        //Angle
        angleStr += QString("phi%1 - phi%2 - (%3 - %4);").arg(pJoint->slide->id).
                                                          arg(pJoint->pJointConnectingItem->id).
                                                          arg(pJoint->slide->getRectAngleRadians()).
                                                          arg(pJoint->pJointConnectingItem->getRectAngleRadians());
        out << translationStr << '\n' << flush;
        out << angleStr << '\n' << flush;
    }
}

void MatlabFile::genDrivingEqn(QTextStream &out)
{
//    qDebug() << "genDrivingEqn";
    foreach(NewBar* item, totalBarList){
        if(item->isDrivingLink == true){
            out << QString("phi%1 - (%2 + (%3)*T + 0.5*(%4)*T )").arg(item->id).arg(item->getRectAngleRadians()).
                                                      arg(item->getAngularVel()).arg(item->getAngularAcc());
            break;
        }
    }
}

void MatlabFile::genFConstrEqnEnding(QTextStream &out)
{
//    qDebug() << "genFConstrEqnEnding";
    out << QString("];")  << '\n' << flush;
}

void MatlabFile::genJaco4barOpening(QTextStream &out)
{
//    qDebug() << "genJaco4BarOpening";

    out << QString("function ") << getJaco4BarStr() << "\n" << "\n" << flush;

    out << QString("global") << '\t';
    for(QList<NewBar *>::iterator i = totalBarList.begin(); i != totalBarList.end(); i++){
        if((*i)->id != 0)
            out << QString("L%1").arg((*i)->id) << "\t";
    }
    out << "\n" << flush;

    out << QString("JacoMatrix = [ ") << "\n" << flush;
}

void MatlabFile::genJaco4bar(QTextStream &out)
{

    //Include GROUND
    foreach(NewBar* item, totalBarList){
        if(item->id == 0){
            out << QString("1 0 0 0 0 0 0 0 0 0 0 0;") << "\n" << flush;
            out << QString("0 1 0 0 0 0 0 0 0 0 0 0;") << "\n" << flush;
            out << QString("0 0 1 0 0 0 0 0 0 0 0 0;") << "\n" << flush;
            break;
        }
    }

    foreach(RevolutionJoint* rJoint, RJointList){
            if( typeid(*rJoint->pinA->parentItem()) == typeid(NewBar) ){
                    if(typeid(*rJoint->pinB->parentItem()) == typeid(NewBar)){
    //                    qDebug() << "A-> BAR/ B-> BAR";
                            NewBar* barA = static_cast<NewBar *>(rJoint->pinA->parentItem());
                            NewBar* barB = static_cast<NewBar *>(rJoint->pinB->parentItem());

                                QString str_x;
                                QString str_y;
                                for(int i =0; i<idList.size(); i++){
                                    if(idList[i] == barA->id){
                                        if(rJoint->pinA->name == "left"){
                                            str_x += QString("1 0 0.5*L%1 * ( sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * (-cos(phi%1)) ").arg(barA->id);
                                        }else if(rJoint->pinA->name == "right"){
                                            str_x += QString("1 0 0.5*L%1 * (-sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * ( cos(phi%1)) ").arg(barA->id);
                                        }
                                    }
                                    else if(idList[i] == barB->id){
                                        if(rJoint->pinB->name == "left"){
                                            str_x += QString("-1 0 -0.5*L%1 * ( sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * (-cos(phi%1)) ").arg(barB->id);
                                        }else if(rJoint->pinB->name == "right"){
                                            str_x += QString("-1 0 -0.5*L%1 * (-sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * ( cos(phi%1)) ").arg(barB->id);
                                        }
                                    }else{
                                        str_x += QString("0 0 0 ");
                                        str_y += QString("0 0 0 ");
                                    }
                                }

                                str_x.chop(1);
                                str_y.chop(1);

                                out << str_x << QString(";") << "\n" << flush;
                                out << str_y << QString(";") << "\n" << flush;
                            barA = NULL;
                            barB = NULL;
                    }else if(typeid(*rJoint->pinB->parentItem()) == typeid(Slide)){
    //                    qDebug() << "A-> BAR/ B-> SLIDE";
                            NewBar* barA = static_cast<NewBar *>(rJoint->pinA->parentItem());
                            Slide* slideB = static_cast<Slide *>(rJoint->pinB->parentItem());

                                QString str_x;
                                QString str_y;
                                for(int i =0; i<idList.size(); i++){
                                    if(idList[i] == barA->id){
                                        if(rJoint->pinA->name == "left"){
                                            str_x += QString("1 0 0.5*L%1 * ( sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * (-cos(phi%1)) ").arg(barA->id);
                                        }else if(rJoint->pinA->name == "right"){
                                            str_x += QString("1 0 0.5*L%1 * (-sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * ( cos(phi%1)) ").arg(barA->id);
                                        }
                                    }
                                    else if(idList[i] == slideB->id){
//                                        qDebug() << "FOUND SLIDE";
                                        if(rJoint->pinB->name == "middle"){
                                            str_x += QString("-1 0 0 ");
                                            str_y += QString("0 -1 0 ");
                                        }
                                    }else{
                                        str_x += QString("0 0 0 ");
                                        str_y += QString("0 0 0 ");
                                    }
                                }

                                str_x.chop(1);
                                str_y.chop(1);

                                out << str_x << QString(";") << "\n" << flush;
                                out << str_y << QString(";") << "\n" << flush;

                            barA = NULL;
                            slideB = NULL;
                    }else if(typeid(*rJoint->pinB->parentItem()) == typeid(Anchor)){
    //                    qDebug() << "A-> BAR/ B-> ANCHOR";
                            NewBar* barA = static_cast<NewBar *>(rJoint->pinA->parentItem());

                                QString str_x;
                                QString str_y;
                                for(int i =0; i<idList.size(); i++){
                                    if(idList[i] == barA->id){
                                        if(rJoint->pinA->name == "left"){
                                            str_x += QString("1 0 0.5*L%1 * ( sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * (-cos(phi%1)) ").arg(barA->id);
                                        }else if(rJoint->pinA->name == "right"){
                                            str_x += QString("1 0 0.5*L%1 * (-sin(phi%1)) ").arg(barA->id);
                                            str_y += QString("0 1 0.5*L%1 * ( cos(phi%1)) ").arg(barA->id);
                                        }
                                    }
                                    else if(idList[i] == 0){
//                                            qDebug() << "FOUND ANCHOR";
                                            str_x += QString("-1 0 0 ");
                                            str_y += QString("0 -1 0 ");

                                    }else{
                                        str_x += QString("0 0 0 ");
                                        str_y += QString("0 0 0 ");
                                    }
                                }

                                str_x.chop(1);
                                str_y.chop(1);

                                out << str_x << QString(";") << "\n" << flush;
                                out << str_y << QString(";") << "\n" << flush;

                            barA = NULL;
                    }
            }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Slide)){
                    if(typeid(*rJoint->pinB->parentItem()) == typeid(NewBar)){
    //                    qDebug() << "A-> SLIDE/ B-> BAR";
                            Slide* slideA = static_cast<Slide *>(rJoint->pinA->parentItem());
                            NewBar* barB = static_cast<NewBar *>(rJoint->pinB->parentItem());

                                QString str_x;
                                QString str_y;
                                for(int i =0; i<idList.size(); i++){
                                    if(idList[i] == slideA->id){
                                        str_x += QString("1 0 0 ");
                                        str_y += QString("0 1 0 ");
                                    }else if(idList[i] == barB->id){
                                        if(rJoint->pinB->name == "left"){
                                            str_x += QString("-1 0 -0.5*L%1 * ( sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * (-cos(phi%1)) ").arg(barB->id);
                                        }else if(rJoint->pinB->name == "right"){
                                            str_x += QString("-1 0 -0.5*L%1 * (-sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * ( cos(phi%1)) ").arg(barB->id);
                                        }
                                    }else{
                                        str_x += QString("0 0 0 ");
                                        str_y += QString("0 0 0 ");
                                    }
                                }

                                str_x.chop(1);
                                str_y.chop(1);

                                out << str_x << QString(";") << "\n" << flush;
                                out << str_y << QString(";") << "\n" << flush;
                            slideA = NULL;
                            barB = NULL;
                    }

            }else if(typeid(*rJoint->pinA->parentItem()) == typeid(Anchor)){
                    if(typeid(*rJoint->pinB->parentItem()) == typeid(NewBar)){
    //                    qDebug() << "A-> ANCHOR/ B-> BAR";
                            NewBar* barB = static_cast<NewBar *>(rJoint->pinB->parentItem());
                            QString str_x;
                            QString str_y;

                                for(int i =0; i<idList.size(); i++){
                                    if(idList[i] == 0){
                                        str_x += QString("1 0 0 ");
                                        str_y += QString("0 1 0 ");
                                    }else if(idList[i] == barB->id){
                                        if(rJoint->pinB->name == "left"){
                                            str_x += QString("-1 0 -0.5*L%1 * ( sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * (-cos(phi%1)) ").arg(barB->id);
                                        }else if(rJoint->pinB->name == "right"){
                                            str_x += QString("-1 0 -0.5*L%1 * (-sin(phi%1)) ").arg(barB->id);
                                            str_y += QString("0 -1 -0.5*L%1 * ( cos(phi%1)) ").arg(barB->id);
                                        }
                                    }else{
                                        str_x += QString("0 0 0 ");
                                        str_y += QString("0 0 0 ");
                                    }
                                }

                                str_x.chop(1);
                                str_y.chop(1);

                                out << str_x << QString(";") << "\n" << flush;
                                out << str_y << QString(";") << "\n" << flush;
                            barB = NULL;
                    }
            }
    }

    foreach(PrismaticJoint* pJoint, PJointList){

        //Translation
        QString translationStr;
        QString angleStr;

        int slideId = pJoint->slide->id;
        int pJointConnectingId = pJoint->pJointConnectingItem->id;
        double vector_x = pJoint->getLocalVectorToTranslationAxis().x();
        double vector_y = pJoint->getLocalVectorToTranslationAxis().y();

        QList<int>::iterator iter = idList.begin();
        for(; iter != idList.end(); iter++){
            if(*iter == slideId){
                QString xStr = QString("sin(phi%1)").arg(slideId);
                QString yStr = QString("-cos(phi%1)").arg(slideId);
                QString phiStr_x = QString("(x%1 - x%2)*cos(phi%1)").arg(slideId).arg(pJointConnectingId);
                QString phiStr_y = QString("(y%1 - y%2)*sin(phi%1)").arg(slideId).arg(pJointConnectingId);
                QString phiStr_cos = QString("(%3)*(cos(phi%1)*cos(phi%2) + sin(phi%1)*sin(phi%2))").arg(slideId).
                                                                                                   arg(pJointConnectingId).
                                                                                                   arg(vector_x);
                QString phiStr_sin = QString("(%3)*(sin(phi%1)*cos(phi%2) - cos(phi%1)*sin(phi%2))").arg(slideId).
                                                                                                   arg(pJointConnectingId).
                                                                                                   arg(vector_y);

                QString phiStr = phiStr_x + QString(" + ") +phiStr_y + QString(" - ") + phiStr_cos + QString(" - ") + phiStr_sin;

                translationStr += (xStr + QString(" ") + yStr + QString(" ") + phiStr + QString(" "));

            }else if(*iter == pJointConnectingId){
                QString xStr = QString("-sin(phi%1)").arg(pJointConnectingId);
                QString yStr = QString("cos(phi%1)").arg(pJointConnectingId);
                QString phiStr_cos = QString("(%3)*(cos(phi%1)*cos(phi%2) + sin(phi%1)*sin(phi%2))").arg(slideId).
                                                                                                   arg(pJointConnectingId).
                                                                                                   arg(vector_x);
                QString phiStr_sin = QString("(%3)*(sin(phi%1)*cos(phi%2) - cos(phi%1)*sin(phi%2))").arg(slideId).
                                                                                                   arg(pJointConnectingId).
                                                                                                   arg(vector_y);
                QString phiStr = phiStr_cos + QString(" + ") +phiStr_sin;

                translationStr += (xStr + QString(" ") + yStr + QString(" ") + phiStr + QString(" "));
            }else{
                translationStr += QString("0 0 0 ");
            }
        }

        //Angle
        iter = idList.begin();
        for(; iter != idList.end(); iter++){
            if(*iter == slideId){
                angleStr += QString("0 0 1 ");
            }else if(*iter == pJointConnectingId){
                angleStr += QString("0 0 -1 ");
            }else{
                angleStr += QString("0 0 0 ");
            }
        }

        translationStr.chop(1);
        angleStr.chop(1);
        out << translationStr << QString(";") << "\n" << flush;
        out << angleStr << QString(";") << "\n" << flush;

    }


}

void MatlabFile::genJaco4barDriving(QTextStream &out)
{
    //genJaco4barDriving
    foreach(NewBar* item, totalBarList){
        if(item->isDrivingLink == true){

            QString drivingStr;
            for(int i =0; i<idList.size(); i++){
                if(idList[i] == item->id)
                    drivingStr += QString("0 0 1 ");
                else
                    drivingStr += QString("0 0 0 ");
            }

            drivingStr.chop(1); //delete the last extra backspace
            out << drivingStr << QString(";") << "\n" << flush ;
            break;
        }
    }
}

void MatlabFile::genJaco4barEnding(QTextStream &out)
{
    out << QString("];") << "\n" << flush;
}

void MatlabFile::genGamma4barOpening(QTextStream &out)
{
//    qDebug() << "genGamma4barOpening";
    out << QString("function ") << getGamma4BarStr() << "\n\n" << flush;

    out << QString("global") << '\t';
    for(QList<NewBar *>::iterator i = totalBarList.begin(); i != totalBarList.end(); i++){
        if((*i)->id != 0)
            out << QString("L%1").arg((*i)->id) << "\t";
    }
    out << "\n" << flush;

    out << "\n" << QString("Gamma=[") << "\n" << flush;
}

void MatlabFile::genGamma4bar(QTextStream &out)
{
//    qDebug() << "genGamma4bar";

    //GROUND
    out << QString("0;") << "\n" << flush;
    out << QString("0;") << "\n" << flush;
    out << QString("0;") << "\n" << flush;

    foreach(RevolutionJoint* rJoint, RJointList){
        QString str_x;
        QString str_y;

        if(typeid(*rJoint->pinA->parentItem()) == typeid(NewBar)){
            if(rJoint->pinA->name == "left"){
                int barId = static_cast<NewBar *>(rJoint->pinA->parentItem())->id;
                str_x += QString("( -0.5*L%1*cos(phi%1)*dphi%1^2 )").arg(barId);
                str_y += QString("( -0.5*L%1*sin(phi%1)*dphi%1^2 )").arg(barId);

            }else if(rJoint->pinA->name == "right"){
                int barId = static_cast<NewBar *>(rJoint->pinA->parentItem())->id;
                str_x += QString("( 0.5*L%1*cos(phi%1)*dphi%1^2 )").arg(barId);
                str_y += QString("( 0.5*L%1*sin(phi%1)*dphi%1^2 )").arg(barId);
            }
        }

        if(typeid(*rJoint->pinB->parentItem()) == typeid(NewBar)){

            str_x += QString(" - ");
            str_y += QString(" - ");

            if(rJoint->pinB->name == "left"){
                int barId = static_cast<NewBar *>(rJoint->pinB->parentItem())->id;
                str_x += QString("( -0.5*L%1*cos(phi%1)*dphi%1^2 )").arg(barId);
                str_y += QString("( -0.5*L%1*sin(phi%1)*dphi%1^2 )").arg(barId);
            }else if(rJoint->pinB->name == "right"){
                int barId = static_cast<NewBar *>(rJoint->pinB->parentItem())->id;
                str_x += QString("( 0.5*L%1*cos(phi%1)*dphi%1^2 )").arg(barId);
                str_y += QString("( 0.5*L%1*sin(phi%1)*dphi%1^2 )").arg(barId);
            }
        }

            out << (str_x + QString(";")) << "\n" << flush;
            out << (str_y + QString(";")) << "\n" << flush;
    }

    foreach(PrismaticJoint* pJoint, PJointList){

        QString translationStr;
        QString angleStr;

        int slideId = pJoint->slide->id;
        int pJointConnectingId = pJoint->pJointConnectingItem->id;
        double vector_x = pJoint->getLocalVectorToTranslationAxis().x();
        double vector_y = pJoint->getLocalVectorToTranslationAxis().y();
        //translation
            // 0 = pJointConnectingId   3 = slideID
            // a = vector_x     b = vector_y

            // str_angle = (phi0 - phi3)^2 * (a*sin(phi0 - phi3) + b*cos(phi0 - phi3))
            // str_Xvel  = 2*(dx0 - dx3) * cos(phi3) * (dphi3)
            // str_Yvel  = 2*(dy0 - dy3) * sin(phi3) * (dphi3)
            // str_Xpos  = (x0 - x3) * sin(phi3) * (dphi3)^2
            // str_Ypos  = (y0 - y3) * cos(phi3) * (dphi3)^2

            // equation = str_angle + str_Xvel + str_Yvel - str_Xpos + str_Ypos

            QString str_angle = QString("(phi%1 - phi%2)^2 * ((%3)*sin(phi%1 - phi%2) + (%4)*cos(phi%1 - phi%2))").arg(pJointConnectingId).
                                                                                                                   arg(slideId).
                                                                                                                   arg(vector_x).
                                                                                                                   arg(vector_y);
            QString str_Xvel = QString("2*(dx%1 - dx%2)*cos(phi%2)*(dphi%2)").arg(pJointConnectingId).arg(slideId);
            QString str_Yvel = QString("2*(dy%1 - dy%2)*sin(phi%2)*(dphi%2)").arg(pJointConnectingId).arg(slideId);

            QString str_Xpos = QString("(x%1 - x%2)*sin(phi%2)*(dphi%2)^2").arg(pJointConnectingId).arg(slideId);
            QString str_Ypos = QString("(y%1 - y%2)*cos(phi%2)*(dphi%2)^2").arg(pJointConnectingId).arg(slideId);

            translationStr += ( str_angle + QString(" + ") + str_Xvel + QString(" + ") + str_Yvel +
                                QString(" - ") + str_Xpos + QString(" + ") + str_Ypos + QString(";"));

        //angle
            angleStr += QString("0;");

        out << translationStr << "\n" << flush;
        out << angleStr << "\n" << flush;
    }

}

void MatlabFile::genGamma4barDriving(QTextStream &out)
{
//    qDebug() << "genGamma4barDriving";
    out << QString("0") << "\n" << flush;
}

void MatlabFile::genGamma4barEnding(QTextStream &out)
{
//    qDebug() << "genGamma4barEnding";
    out << QString("];") << "\n" << flush;
}

void MatlabFile::setTotalItemList(QList<QGraphicsItem *> _totalItemsList)
{
    totalItemsList = _totalItemsList;
    //    qDebug() << "totalItemList is UP-TO-DATE";
}

void MatlabFile::setTime(int _time)
{
    totalTime = _time;
}

void MatlabFile::getTotalItemListFromDisplay(QList<QGraphicsItem *> _totalItemsList)
{
    setTotalItemList(_totalItemsList);
}

void MatlabFile::getTimeFromDisplay(int _time)
{
    setTime(_time);
}

