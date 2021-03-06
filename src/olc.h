/***************************************************************************
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *
 *  Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.   *
 *                                                                         *
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *
 *  Chastain, Michael Quan, and Mitchell Tse.                              *
 *                                                                         *
 *  Envy Diku Mud improvements copyright (C) 1994 by Michael Quan, David   *
 *  Love, Guilherme 'Willie' Arnold, and Mitchell Tse.                     *
 *                                                                         *
 *  EnvyMud 2.0 improvements copyright (C) 1995 by Michael Quan and        *
 *  Mitchell Tse.                                                          *
 *                                                                         *
 *  EnvyMud 2.2 improvements copyright (C) 1996, 1997 by Michael Quan.     *
 *                                                                         *
 *  GreedMud 0.99.3 improvements copyright (C) 1997, 1998, 1999            *
 *  by Vasco Costa.                                                        *
 *                                                                         *
 *  In order to use any part of this Envy Diku Mud, you must comply with   *
 *  the original Diku license in 'license.doc', the Merc license in        *
 *  'license.txt', as well as the Envy license in 'license.nvy'.           *
 *  In particular, you may not remove either of these copyright notices.   *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 *                                                                         *
 *  This code was freely distributed with the The Isles 1.1 source code,   *
 *  and has been used here for OLC - OLC would not be what it is without   *
 *  all the previous coders who released their source code.                *
 ***************************************************************************/

/*
 * This is a header file for all the OLC files.
 * Feel free to copy it into merc.h if you wish.
 * Many of these routines may be handy elsewhere in the code.
 * -- Jason Dinkel --
 */


/*
 * This is displayed in the game by typing 'version' while editing.
 * Do not remove these from the code - by request of Jason Dinkel
 */
#define	OLC_CREDITS "ILAB Online Creation [Beta 1.1]\n\r"	 	      \
		    "     By Jason Dinkel\n\r"			 	      \
		    "     (May. 15, 1995)\n\r"			 	      \
		    "     Original by Surreality and Locke from TheIsles\n\r" \
		    "     Enhanced & Debugged by Zen for GreedMud\n\r"


struct olc_help_type
{
    char *		command;
    const void *	structure;
    char *		desc;
};


/*
 * Interpreter prototypes.
 */
void	aedit	args( ( CHAR_DATA *ch, char *argument ) );
void	redit	args( ( CHAR_DATA *ch, char *argument ) );
void	medit	args( ( CHAR_DATA *ch, char *argument ) );
void	oedit	args( ( CHAR_DATA *ch, char *argument ) );
void	mpedit	args( ( CHAR_DATA *ch, char *argument ) );


/*
 * Prototypes.
 */
#define ARD	AREA_DATA
#define RD	RESET_DATA
#define EXD	EXIT_DATA
#define SD	SHOP_DATA
#define GD	GAME_DATA
#define AFD	AFFECT_DATA
#define MPD	MPROG_DATA
#define RID	ROOM_INDEX_DATA
#define OID	OBJ_INDEX_DATA
#define MID	MOB_INDEX_DATA
#define ED	EXTRA_DESCR_DATA

/* mem.c */
RD *	new_reset_data 	args( ( void ) );
ARD *	new_area 	args( ( void ) );
EXD *	new_exit 	args( ( void ) );
AFD *	new_affect 	args( ( void ) );
SD *	new_shop 	args( ( void ) );
GD *	new_game 	args( ( void ) );
void 	free_reset_data args( ( RESET_DATA *pReset ) );
void 	free_area 	args( ( AREA_DATA *pArea ) );
void 	free_exit 	args( ( EXIT_DATA *pExit ) );
void 	free_extra_descr 	args( ( ED *pExtra ) );
void 	free_affect 	args( ( AFFECT_DATA *pAf ) );
void 	free_shop 	args( ( SHOP_DATA *pGame ) );
void 	free_game 	args( ( GAME_DATA *pGame ) );
RID *	new_room_index 	args( ( void ) );
OID *	new_obj_index 	args( ( void ) );
MID *	new_mob_index 	args( ( void ) );
void 	free_room_index args( ( ROOM_INDEX_DATA *pRoom ) );
void 	free_obj_index 	args( ( OBJ_INDEX_DATA *pObj ) );
void 	free_mob_index 	args( ( MOB_INDEX_DATA *pMob ) );

/* bit.c */
int	flag_value	args( ( const FLAG_TYPE *table, char *argument ) );
const char *	flag_string	args( ( const FLAG_TYPE *table, int bits ) );
const char *	flag_strings	args( ( const FLAG_TYPE *table, int bits ) );
int	vect_value	args( ( const FLAG_TYPE *table, char *arg, XBV vector ) );
int	fread_flag	args( ( FILE *fp, const FLAG_TYPE *table ) );
int	wear_loc	args( ( int bits, int count ) );
int	wear_bit	args( ( int loc ) );

/* act_olc.c */
ARD *	get_area_data 	args( ( int vnum ) );
void	add_reset	args( ( ROOM_INDEX_DATA *room, RESET_DATA *pReset,
			       int index ) );
ARD *	get_vnum_area 	args( ( int vnum ) );

#undef	ARD
#undef	RD
#undef	EXD
#undef	SD
#undef	GD
#undef	AFD
#undef	MPD
#undef	RID
#undef	OID
#undef	MID
#undef	ED
