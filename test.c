#include <mlx.h>
#include <stdio.h>


int key_press_event(int keycode)
{
	if (keycode == 53)
		exit(0);
	printf("keycode : %d\n", keycode);
	return 0;

}
int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 200, "mlx 42");
	mlx_hook(win,2, 1L<<0,  key_press_event, (void *)0);
	mlx_loop(mlx);
	return (0);
}
