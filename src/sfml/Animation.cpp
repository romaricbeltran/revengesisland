#include "Animation.h"

using namespace std;
using namespace sf;
Animation::Animation()
{

}

Animation::Animation(sf::Texture &t, int x, int y, int w, int h, int Count, float Speed)
{
    Frame=0;
    speed=Speed;

    for(int i=0; i<Count; i++)
    {
        frames.push_back(sf::IntRect(x+i*w, y, w,h));
    }
    sp.setTexture(t);
    sp.setOrigin(w/2,h/2);
    sp.setTextureRect(frames[0]);

}

void Animation::update()
{
    Frame+=speed;
    int n=frames.size();
    if(Frame>=n) Frame-=n;
    if(n>0) sp.setTextureRect(frames[int(Frame)]);
}

	bool Animation::isEnd()
	{
	  return Frame+speed>=frames.size();
	}
