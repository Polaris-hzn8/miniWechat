/*************************************************************************
	> File Name: imfunc.c
	> Author: luochenhao
	> Mail: 3453851623@qq.com
	> Created Time: Tue 18 Apr 2023 04:39:00 PM CST
 ************************************************************************/

#include "include/imfunc.h"

void broadcast(struct wechat_msg msg) {
	for (int i = 0; i < MAXUSERS; ++i) {
		if (users[i].isOnline && strcmp(users[i].name, msg.from)) {
			DBG(RED"<Sub Reactor-broadcast>"NONE" : %d shall be broadcasted a message <%s>.\n", users[i].fd, msg.content);
			send(users[i].fd, (void *)&msg, sizeof(msg), 0);
		}
	}
}

