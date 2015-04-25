#include "areacoveringalgorithm.h"
#include <chrono>
#include <thread>
#include "iostream"
#define left Dimension(-1,0)
#define right Dimension(1,0)
#define forward Dimension(0,-1)
#define down Dimension(0,1)

AreaCoveringAlgorithm::AreaCoveringAlgorithm(TestCopter copter, ArrayMap* mapp)
{
    globalmap=mapp;
    followCovered(&copter,mapp,1,3);
    this->drawWayPoints(mapp);



}
void AreaCoveringAlgorithm::drawWayPoints(ArrayMap* map){

    for(WayPoint point:result){
        map->data.at(point.x)->at(point.y)=15;


    }



}
bool AreaCoveringAlgorithm::testCoverage(){
    if (globalmap->contains(0)){std::cout <<"Not all areas covered, alg failed"; return false;}
    else{std::cout <<"No Spaces left unchecked, Coverage Route Succes";return true;}

}
int AreaCoveringAlgorithm::followWall(TestCopter* copter, ArrayMap* mapp,int wallnumber){
    this->registerLocation(mapp,copter);

    Dimension direction(0,0);
    direction.height=1;
    int sightxinitial = copter->copterSight.width-1;
    for(int x=0; x<800;x++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        this->registerLocation(mapp,copter);
        if(pointOn(direction.width*sightxinitial,direction.height*sightxinitial,copter,mapp)== 3){return x;}
        if(pointOn(direction.width,direction.height,copter,mapp)== wallnumber) //Als er iets in de wegstaat voor de copter
        {
            if(direction == down) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(-1,0,copter,mapp)==wallnumber) //En de copter kan niet naar rechts
                {
                direction = Dimension(1,0);}

            else{direction=Dimension(-1,0);}
            }
            else if(direction == right) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(0,1,copter,mapp)==wallnumber) //En de copter kan niet naar beneden
                {
                direction = Dimension(0,-1);}

            else{direction=Dimension(0,1);}
            }
            else if(direction == left) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(0,-1,copter,mapp)==wallnumber) //En de copter kan niet omhoog
                {
                direction = Dimension(0,1);}

            else{direction=Dimension(0,-1);}
            }
            else if(direction == forward) //als hij op het scherm naar beneden gaat
            {
                if(pointOn(1,0,copter,mapp)==wallnumber) //En de copter kan niet naar beneden
                {
                direction = Dimension(-1,0);}

            else{direction=Dimension(1,0);}
            }



            //direction= Dimension(1,0);
        }
        copter->x= copter->x+direction.width;
        copter->y=copter->y+direction.height;


    }
    return 0;
}
int AreaCoveringAlgorithm::followCovered(TestCopter* copter, ArrayMap* mapp,int wallnumber,int coveredNumber){


    Dimension direction(0,0);
    direction.height=1;
    int sightxinitial = copter->copterSight.width-1;
    for(int x=0; x<500;x++){
        this->registerLocation(mapp,copter);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));


        //if(pointOn(direction.width*sightxinitial,direction.height*sightxinitial,copter,mapp)== 3){QTextStream(stdout) <<"return";return x;}
        if(pointOn(direction.width,direction.height,copter,mapp)== wallnumber||pointOn(direction.width*(sightxinitial),direction.height*(sightxinitial),copter,mapp)== coveredNumber) //Als er iets in de wegstaat voor de copter
        {
            if(direction == down) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(-1,0,copter,mapp)==wallnumber||pointOn(-1*(sightxinitial),0,copter,mapp)==coveredNumber) //En de copter kan niet naar rechts
                {
                direction = Dimension(1,0);}

            else{direction=Dimension(-1,0);}
            }
            else if(direction == right) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(0,1,copter,mapp)==wallnumber||pointOn(0,1*(sightxinitial),copter,mapp)==coveredNumber) //En de copter kan niet naar beneden
                {
                direction = Dimension(0,-1);}

            else{direction=Dimension(0,1);}
            }
            else if(direction == left) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(0,-1,copter,mapp)==wallnumber||pointOn(0,-1*(sightxinitial),copter,mapp)==coveredNumber) //En de copter kan niet omhoog
                {
                direction = Dimension(0,1);}

            else{direction=Dimension(0,-1);}
            }
            else if(direction == forward) //als hij op het scherm naar beneden gaat
            {

                if(pointOn(1,0,copter,mapp)==wallnumber||pointOn(-1*(sightxinitial),0,copter,mapp)==coveredNumber) //En de copter kan niet naar beneden
                {
                direction = Dimension(-1,0);}









            else{direction=Dimension(1,0);}
            }



            //direction= Dimension(1,0);
        }
        copter->x= copter->x+direction.width;
        copter->y=copter->y+direction.height;


    }
    this->registerLocation(mapp,copter);
    return 0;
}
int AreaCoveringAlgorithm::pointOn(int x, int y,TestCopter* copter, ArrayMap* map){
    if(copter->x+x<map->data.size()&&copter->x+x>-1){

        if(copter->y+y>-1&& copter->y+y<map->data.at(copter->x)->size()){
    return map->data.at(copter->x+x)->at(copter->y+y);}
    else {return 1;}
}




}
void AreaCoveringAlgorithm::registerLocation(ArrayMap* map, TestCopter* copter)
{
    result.push_back(WayPoint(copter->x,copter->y));
    int sightxinitial = copter->copterSight.width-1;
    sightxinitial = sightxinitial/2;
    //werkt wel voor x en y omdat ie toch vierkant is, zo niet dan moet ik een sight y initial maken
    for(int i =copter->x-sightxinitial; i<= copter->x+sightxinitial;i++){

         for(int ii =copter->y-sightxinitial; ii<= copter->y+sightxinitial;ii++){
             if(i<map->data.size()&&i>-1&& ii>-1&& ii<map->data.at(i)->size()){
             if(map->data.at(i)->at(ii)==0){map->data.at(i)->at(ii)=3;}
             }


         }





    }



}
/*void AreaCoveringAlgorithm::getCells(Map map){
    bool lastwasnull=false;
//    map.print();
    int x=0;
    int y=0;
    while(true){
        Tile* t =map.getTileAt(x,y);
       if(t!=nullptr&&t->type=='0'&& !isInCell(t)){
       QTextStream(stdout) << t->x << "  "<< t->y << "\n";
       getCellFrom(map,t);
    }


    x++;
    if(t==nullptr){x=0;y++;
        if(lastwasnull==true){break;}

        lastwasnull=true;}

    else{lastwasnull=false;}


}


}*/
AreaCoveringAlgorithm::~AreaCoveringAlgorithm()
{

}

/*void AreaCoveringAlgorithm::getCellFrom(Map map, Tile* source){
    Tile* xMax;
    bool firstJump=true;
    bool lastnull=false;
    Cell product;
    int x=source->x;
    int y=source->y;
     QTextStream(stdout) << x << " " <<y << "geting cell from \n";
    while(true){

    Tile* checking = map.getTileAt(x,y);
    if (checking!=nullptr &&checking->type=='0'&& !isInCell(checking))
    {
        if(lastnull&&checking->x!=source->x){break;}
        QTextStream(stdout) << checking->x << "  "<< checking->y << " geting cell \n";

        product.tiles.push_back(checking);
        x++;
        lastnull=false;
        if(firstJump){xMax =checking;}
    }

    else{y++;x=source->x;if(lastnull==true){break;}lastnull=true;firstJump=false;}
    if(firstJump!=true&&checking->x==xMax->x){y++;x=source->x;if(lastnull==true){break;}lastnull=true;firstJump=false;}


    }
    cells.push_back(product);

}*/
/*bool AreaCoveringAlgorithm::isInCell(Tile *t){
    for(Cell cell: cells){
        if(cell.contains(t)){return true;}



    }
    return false;





}*/
/*void AreaCoveringAlgorithm::generateCellPath(Cell c){



}*/
void AreaCoveringAlgorithm::setCopterSquare(TestCopter copt, ArrayMap* map){
    map->data.at(copt.x)->at(copt.y)=10;


}
