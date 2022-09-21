// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function Checkmouse(x,y,H,W){
if(mouse_x<=x+W/2&&mouse_x>=x-W/2)
if(mouse_y<=y&&mouse_y>=y-H)
return true
else
return false
}

