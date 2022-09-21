var en=instance_nearest(x,y,O_p)


if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)>500)
	{
		instance_destroy()
	}
		

}
else
instance_destroy()
