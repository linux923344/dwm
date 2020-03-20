static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     	/* 0 means no systray */
static const char *fonts[]          = { "mono:size=15", "Font Awesome 5 Free Solid:size=15"};
static const char dmenufont[]       = "mono:size=15";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};


static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    { "Gimp",                NULL,       NULL,        0,          True,       -1 },
    { "pulsemixer",          NULL,       NULL,        0,          True,       -1 },
    { "qutebrowser",         NULL,       NULL,        1 << 1,     False,       0 },
    { "Firefox",  			 NULL,       NULL,        1 << 1,     False,       0 },
	{ "Thunderbird",         NULL,       NULL,        1 << 2,     False,       0 },
	{ "Steam",         		 NULL,       NULL,        1 << 3,     False,       0 },
	{ "Lutris",         	 NULL,       NULL,        1 << 3,     False,       0 },
	{ "League of Legends", 	 NULL,       NULL,        1 << 3,     True,        0 },
	{ "TeamSpeak 3",       	 NULL,       NULL,        1 << 3,     False,       0 },
	{ "discord",           	 NULL,       NULL,        1 << 4,     False,       0 },
    { "KeePassXC",           NULL,       NULL,        1 << 7,     False,       0 },
	{ "TeamViewer",    		 NULL,       NULL,        1 << 8,     False,       0 },
    { "obs",         		 NULL,       NULL,        1 << 8,     False,       0 },
};

static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st","-ce", "/bin/zsh" , NULL };
static const char *print_screen_cmd[] = { "screenshot", NULL };
static const char *print_screen_cmd_area[] = { "screenshot-area", NULL };
static const char *cmdlock[]  = { "slock", NULL };
static const char *dwmkill[]  = { "dwm-kill", NULL };
static const char *cmusshell[]  = { "st", "-ce", "cmus-shell",  NULL };
static const char *ranger[]  = { "st", "-ce", "ranger",  NULL };
static const char *mixer[]  = { "st", "-ce", "pulsemixer",  NULL };
static const char *dmenumount[]  = { "dmenumount", NULL };
static const char *dmenuumount[]  = { "dmenuumount", NULL };
static const char *cmusplay[]  = { "cmus-remote", "-u", NULL };
static const char *cmusnext[]  = { "cmus-remote", "-n", NULL };
static const char *cmusprev[]  = { "cmus-remote", "-r", NULL };
static const char *shutdownpress[] = {"shut-sup-rest", "NULL" };
static const char *screenswitcher[] = { "screen-switcher", "NULL" }; 

static Key keys[] = {
	{0,				         0x1008ff02,		spawn, 	        SHCMD ("sudo light -A 10")},
	{0, 			         0x1008ff03, 		spawn,	        SHCMD ("sudo light -U 10")},
	{0, 			         0x1008ff11, 		spawn, 		    SHCMD ("ponymix decrease 5")},
    {0,				         0x1008ff12, 		spawn,		    SHCMD ("ponymix toggle")},
	{0, 			         0x1008ff13, 		spawn,		    SHCMD ("ponymix increase 5")},
	{ MODKEY,		         XK_F2,	   	    	spawn, 		    SHCMD ("ponymix decrease 5")},
    { MODKEY,		         XK_F1,	   	    	spawn,		    SHCMD ("ponymix toggle")},
	{ MODKEY|ShiftMask,	     XK_F2,  	   		spawn,		    SHCMD ("cmus-remote -v -5%")},
	{ MODKEY|ShiftMask,      XK_F3,	       		spawn,		    SHCMD ("cmus-remote -v +5%")},	
	{ MODKEY,		         XK_F3,	   	    	spawn,		    SHCMD ("ponymix increase 5")},
	{ MODKEY, 		         XK_F10,		    spawn,		    {.v = screenswitcher} },
    {0,                      XK_Print,  	    spawn,          {.v = print_screen_cmd } },
    { MODKEY,                XK_Print,  	    spawn,          {.v = print_screen_cmd_area } },
    { MODKEY,		         XK_l,	   		    spawn,	   	    {.v = cmdlock } },		
	{ MODKEY,                XK_d,      		spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,      XK_Return, 		spawn,          {.v = termcmd } },
	{ MODKEY,                XK_b,      		togglebar,      {0} },
	{ MODKEY,                XK_Left,      		focusstack,     {.i = +1 } },
	{ MODKEY,                XK_Right,      	focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,      XK_e,              spawn,          {.v = shutdownpress } },
	{ MODKEY,                XK_o,              spawn,          {.v = mixer } },
	{ MODKEY|ShiftMask,      XK_Left,      		setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,      XK_Right,      	setmfact,       {.f = +0.05} },
    { MODKEY,                XK_Return, 		zoom,           {0} },
	{ MODKEY,                XK_Tab,    		view,           {0} },
	{ MODKEY|ShiftMask,      XK_q,      		killclient,     {0} },
	{ MODKEY,                XK_f,              fullscreen,     {0} },
	{ MODKEY,                XK_space,  		setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,      XK_space,  		togglefloating, {0} },
	{ MODKEY,                XK_0,      		view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,      XK_0,      		tag,            {.ui = ~0 } },
	{ MODKEY,                XK_comma,  		focusmon,       {.i = -1 } },
	{ MODKEY,                XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,      XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,      XK_period, 		tagmon,         {.i = +1 } },
	{ MODKEY,			     XK_k,		        spawn, 		    SHCMD ("qalculate-gtk")},
	{ MODKEY,                XK_r,              spawn,          {.v = ranger }},
	{ MODKEY,             	 XK_m,              spawn,          {.v = cmusshell }},
	{ MODKEY,             	 XK_F4,             spawn,          {.v = dmenumount }},
    { MODKEY,                XK_F5,             spawn,          {.v = dmenuumount }},
	{ MODKEY|ShiftMask,      XK_apostrophe,     spawn,          {.v = cmusplay }},
	{ MODKEY|ShiftMask,      XK_bracketright,   spawn,          {.v = cmusnext }},
	{ MODKEY|ShiftMask,      XK_bracketleft,    spawn,          {.v = cmusprev }},
    { 0,             		 0x1008ff14,        spawn,          {.v = cmusplay }},
    { 0,             		 0x1008ff17,       	spawn,          {.v = cmusnext }},
    { 0,             	     0x1008ff16,        spawn,          {.v = cmusprev }},
    /*{ MODKEY,                       XK_t,     		setlayout,      {.v = &layouts[0]} },*/
	/*{ MODKEY,                       XK_f,      		setlayout,      {.v = &layouts[2]} },*/ 
	/* { MODKEY|ShiftMask,             XK_q,      		spawn,          {.v = dwmkill } }, */ 
	/*{ MODKEY,                       XK_space,  		setlayout,      {0} },*/
	/*{ MODKEY|ShiftMask,      XK_f,      		setlayout,      {.v = &layouts[1]} },*/
    TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

