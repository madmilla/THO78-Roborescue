#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension
{
public:
    bool operator ==(Dimension d ){
        if(this->height==d.height&&this->width==d.width){return true;}
        else{return false;}
    }
    int width,height;
    Dimension(int width,int height);
    ~Dimension();
};

#endif // DIMENSION_H
