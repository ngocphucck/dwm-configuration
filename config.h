/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
#include "themes/onedark.h"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const unsigned int colorfultitle  = 1;  /* 0 means title use SchemeTitle and SchemeTitleFloat */
static const unsigned int colorfultag    = 1;  /* 0 means use SchemeSel for selected tag */
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style:medium:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_bg[]          = "#1a1b26";
static const char col_dark[]        = "#16161E";
static const char col_dark_1[]      = "#232433";
static const char col_dark_2[]      = "#2a2b3d";
static const char col_dark_3[]      = "#3b3d57";
static const char col_fg[]          = "#a9b1d6";
static const char col_black[]       = "#32344a";
static const char col_br_black[]    = "#444b6a";
static const char col_white[]       = "#787c99";
static const char col_br_white[]    = "#acb0d0";
static const char col_red[]         = "#f7768e";
static const char col_br_red[]      = "#ff7a93";
static const char col_green[]       = "#9ece6a";
static const char col_br_green[]    = "#b9f27c";
static const char col_yellow[]      = "#e0af68";
static const char col_br_yellow[]   = "#ff9e64";
static const char col_blue[]        = "#7aa2f7";
static const char col_br_blue[]     = "#7da6ff";
static const char col_magenta[]     = "#ad8ee6";
static const char col_br_magenta[]  = "#bb9af7";
static const char col_cyan[]        = "#449dab";
static const char col_br_cyan[]     = "#0db9d7";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]       = { col_fg,         col_bg,         col_bg },         /* \x0b */
	[SchemeSel]        = { col_blue,       col_dark,       col_red },     /* \x0c */
    [SchemeDarker]     = { col_dark,       col_bg,         col_black },      /* \x0d */
    [SchemeRed]        = { col_red,        col_bg,         col_black },      /* \x0e */
    [SchemeGreen]      = { col_green,      col_bg,         col_black },      /* \x0f */
    [SchemeBlue]       = { col_blue,       col_bg,         col_black },      /* \x10 */
    [SchemeCyan]       = { col_cyan,       col_bg,         col_black },      /* \x11 */
    [SchemeMagenta]    = { col_magenta,    col_bg,         col_black },      /* \x12 */
    [SchemeYellow]     = { col_yellow,     col_bg,         col_black },      /* \x13 */
    [SchemeBlack]      = { col_black,      col_bg,         col_black },      /* \x14 */
    [SchemeWhite]      = { col_white,      col_bg,         col_black },      /* \x15 */
    [SchemeBrRed]      = { col_br_red,     col_bg,         col_black },      /* \x16 */
    [SchemeBrGreen]    = { col_br_green,   col_bg,         col_black },      /* \x17 */
    [SchemeBrBlue]     = { col_br_blue,    col_bg,         col_black },      /* \x18 */
    [SchemeBrCyan]     = { col_br_cyan,    col_bg,         col_black },      /* \x19 */
    [SchemeBrMagenta]  = { col_br_magenta, col_bg,         col_black },      /* \x1a */
    [SchemeBrYellow]   = { col_br_yellow,  col_bg,         col_black },      /* \x1b */
    [SchemeBrBlack]    = { col_br_black,   col_bg,         col_black },      /* \x1c */
    [SchemeBrWhite]    = { col_br_white,   col_bg,         col_black },      /* \x1d */
    [SchemeFloat]      = { col_fg,         col_bg,         col_dark_2 },     /* \x1e */
    [SchemeInactive]   = { col_br_black,   col_bg,         col_black },      /* \x1f */
    [SchemeBar]        = { col_fg,         col_bg,         col_bg },
    [SchemeTag]        = { col_br_black,   col_bg,         col_black },
    [SchemeTag1]       = { col_fg,         col_dark,       col_black },
	[SchemeTag2]       = { col_red,        col_dark,       col_black },
    [SchemeTag3]       = { col_br_yellow,  col_dark,       col_black },
    [SchemeTag4]       = { col_br_blue,    col_dark,       col_black },
    [SchemeTag5]       = { col_br_magenta, col_dark,       col_black },
	[SchemeTag6]       = { col_br_cyan,    col_dark,       col_black },
	[SchemeTag7]       = { col_br_green,   col_dark,       col_black },
	[SchemeTag8]       = { col_yellow,     col_dark,       col_black },
	[SchemeTag9]       = { col_br_red,     col_dark,       col_black },
	[SchemeLayout]     = { col_white,      col_bg,         col_black },
	[SchemeTitle]      = { col_fg,         col_bg,         col_black },
	[SchemeTitleFloat] = { col_br_blue,    col_bg,         col_black },
	[SchemeTitle1]     = { col_fg,         col_bg,         col_black },
	[SchemeTitle2]     = { col_red,        col_bg,         col_black },
        [SchemeTitle3]     = { col_br_yellow,  col_bg,         col_black },
        [SchemeTitle4]     = { col_br_blue,    col_bg,         col_black },
        [SchemeTitle5]     = { col_br_magenta, col_bg,         col_black },
	[SchemeTitle6]     = { col_br_cyan,    col_bg,         col_black },
	[SchemeTitle7]     = { col_br_green,   col_bg,         col_black },
	[SchemeTitle8]     = { col_yellow,     col_bg,         col_black },
	[SchemeTitle9]     = { col_br_red,     col_bg,         col_black },
};

/* tagging */
static const char *tags[] = { " ", " ", " ", " ", "ﭮ ", " "," "};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6,
                                  SchemeTag7, SchemeTag8, SchemeTag9 };
static const int titleschemes[] = { SchemeTitle1, SchemeTitle2, SchemeTitle3,
                                    SchemeTitle4, SchemeTitle5, SchemeTitle6,
                                    SchemeTitle7, SchemeTitle8, SchemeTitle9 };
                                    
static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	//{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",     NULL  };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",     NULL  };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle",  NULL  };
static const char *light_up[] = {"xbacklight", "-inc", "10%", NULL};
static const char *light_down[] = {"xbacklight", "-dec", "10%", NULL};

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_s,      show,           {0} },
	{ MODKEY,                       XK_h,      hide,           {0} },
	{ 0,							XF86XK_AudioLowerVolume,	spawn,		{.v = downvol }  },
	{ 0,							XF86XK_AudioMute,			spawn,      {.v = mutevol }  },
	{ 0,							XF86XK_AudioRaiseVolume,	spawn,		{.v = upvol   }  },
	{ 0,							XF86XK_MonBrightnessUp,		spawn,		{.v = light_up}	 },
	{ 0,							XF86XK_MonBrightnessDown,	spawn,		{.v = light_down}},
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
