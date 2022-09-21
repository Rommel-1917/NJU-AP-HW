if(instance_exists(objecttoshoot))
{
	var bullet=instance_create_depth(x,y-125,-9,O_bullet_h)
	bullet.speed=25;
	bullet.direction=point_direction(x,y,objecttoshoot.x,objecttoshoot.y);
	alarm[0]=fire_rate
}
else
{
	shooting=false
}
