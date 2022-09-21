var en=instance_nearest(x,y,O_p)


if(en !=noone)
{
	if(point_distance(x,y,en.x,en.y)<=500 )
	{
		if(iscreat==0)
		{
		iscreat=1
		instance_create_depth(x,y,-1,gre)
		}
	}
	
}
