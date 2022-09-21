draw_self()
drawbloodT(global.hp*2,hp)

var en=instance_nearest(x,y,E)

if(Checkmouse(x,y,350,300))
draw_circle(x,y-150,range,1)
if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)<=range)
	{
		sprite_index=C_attack
		if(!shooting)
		{
			alarm[0]=1;
			shooting=true;
		}
		objecttoshoot=en
	}
	else{
		sprite_index=C_stand
		shooting=false;
		objecttoshoot=noone
	}
}
else
{
	sprite_index=C_stand
}
