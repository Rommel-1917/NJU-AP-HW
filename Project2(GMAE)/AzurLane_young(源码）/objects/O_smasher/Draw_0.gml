draw_self()
drawbloodA(global.hp,hp)

var en=instance_nearest(x,y,T_s)
if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)<=range)
	{
		sprite_index=S_ANEMY1_attack
		if(!shooting)
		{
			alarm[0]=1;
			shooting=true;
		}
		objecttoshoot=en
	}
	else{
		sprite_index=S_ANEMY1_move
		shooting=false;
		objecttoshoot=noone
	}
}
else
sprite_index=S_ANEMY1_move

