draw_self()
drawbloodT(global.hp*0.5,hp)
var en=instance_nearest(x,y,O_z23)

if(Checkmouse(x,y,350,300))
draw_circle(x,y-150,range,1)
if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)<=range)
	{
		
		if(!shooting)
		{
			alarm[0]=1;
			shooting=true;
		}
		objecttoshoot=en
	}
	else{
		
		shooting=false;
		objecttoshoot=noone
	}
}

