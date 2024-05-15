void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void open_window(void)
{
	void	*mlx;
	void	*mlx_win;
	/*open the window -->*/
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 600, "So_long");
	/*Put image in the window*/
	t_data	img;
	img.img = mlx_new_image(mlx, 1000, 600);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 5;
	int y = 5;	
	while(x < 500 && y < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	if(y == 500 && x == 500)
	{
		x = 5;
		y = 500;
		while(x < 500)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
	}
	x = 5;
	y = 5;
	while (y < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
	}
	x = 100;
	y = 100;
	while(x < 400)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		
		if(x == 400)
		{
			while(y < 400)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
				y++;
			}
		}
	}
	y = 500;
	x  = 5;
	while(x < 400 || y == 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y--;
		x++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	/*for looping and stay windows running -->*/
	mlx_loop(mlx);
	return ;
}
/* this function for try using pixles in window*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main ()
{
	open_window();
	return (0);
}
