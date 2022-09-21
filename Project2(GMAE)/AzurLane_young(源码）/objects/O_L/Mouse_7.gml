var t=instance_nearest(x,y,O_c)
if(t!=noone)
{
	if(point_distance(x,y,t.x,t.y)>=50)
	{
	switch global.tower
	{
		case 2:
		if(global.coins>=Object24.cost)
		{
		instance_create_depth(x,y,-1,O_c);
		global.coins-=Object24.cost;
		
		break
		}
	}
	}
}
else
{
	switch global.tower
	{
		case 2:
		if(global.coins>=Object24.cost)
		{
		instance_create_depth(x,y,-1,O_c);
		global.coins-=Object24.cost;
		
		break
		}
	}
}
