draw_self()
drawbloodT(global.hp*2,hp)

var en=instance_nearest(x,y,Anemy)
if(Checkmouse(x,y,350,250))
draw_circle(x,y-125,range,1)
if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)<=range)
	{
		sprite_index=S_Z23attack
		if(!shooting)
		{
			alarm[0]=1;
			shooting=true;
		}
		objecttoshoot=en
	}
	else{
		sprite_index=S_z23
		shooting=false;
		objecttoshoot=noone
	}
}
else
{
	sprite_index=S_z23
}
