if(instance_exists(objecttoshoot))
{
	if(damage==10)
	{
	var bullet=instance_create_depth(x,y-125,-9,O_bullet_l)
	bullet.speed=25;
	bullet.direction=point_direction(x,y,objecttoshoot.x,objecttoshoot.y);
	alarm[0]=fire_rate
	}
	else
	{
			var bullet=instance_create_depth(x,y-125,-9,O_bullet_l33)
	bullet.speed=25;
	bullet.direction=point_direction(x,y,objecttoshoot.x,objecttoshoot.y);
	alarm[0]=fire_rate
	}
}
else
{
	shooting=false
}
