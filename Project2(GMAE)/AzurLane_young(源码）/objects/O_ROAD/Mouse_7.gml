var t=instance_nearest(x,y,T_s)
if(t!=noone)
{
	if(point_distance(x,y,t.x,t.y)>=50)
	{
	switch global.tower
	{
		case 1:
		if(global.coins>=Object3.cost)
		{
		instance_create_depth(x,y,-1,O_z23);
		global.coins-=Object3.cost;
		
		break
		}
		case 3:
		if(global.coins>=Object31.cost)
		{
		instance_create_depth(x,y,-1,O_p);
		global.coins-=Object31.cost;
		
		break
		}
	}
	}
}
else
{
	switch global.tower
	{
		case 1:
		if(global.coins>=Object3.cost)
		{
		instance_create_depth(x,y,-1,O_z23);
		global.coins-=Object3.cost;
		
		break
		}
				case 3:
		if(global.coins>=Object31.cost)
		{
		instance_create_depth(x,y,-1,O_p);
		global.coins-=Object31.cost;
		
		break
		}
	}
}
