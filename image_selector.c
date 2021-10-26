#include "so_long.h"

void	*select_idle_img(t_p_imgs *player, t_p_state *player_state, int state)
{
	if (player_state->direction == LEFT)
		return (player->m_player_idle[state].addr);
	else
		return (player->player_idle[state].addr);
}

void	*select_run_img(t_p_imgs *player, t_p_state *player_state, int state)
{
	if (player_state->direction == LEFT)
		return (player->m_player_run[state].addr);
	else
		return (player->player_run[state].addr);
}
