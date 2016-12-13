#include "internal.h"
#include "debug.h"
#include "plugin.h"
#include "signals.h"
#include "version.h"

/** Plugin id : type-author-name (to guarantee uniqueness) */
#define SIMPLE_PLUGIN_ID "core-chrisoakman-blockaolsystemmsg"

static gboolean
receiving_im_msg_cb(PurpleAccount *account, char **sender, char **buffer, PurpleConversation *conv, PurpleMessageFlags *flags, void *data)
{
	if (strcmp(*sender, "AOL System Msg") == 0) {
		purple_debug(PURPLE_DEBUG_INFO, "block aolsystemmsg plugin", "blocked message from %s\n", *sender);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

static gboolean
plugin_load(PurplePlugin *plugin)
{
	void *conv_handle = purple_conversations_get_handle();
	
	purple_debug(PURPLE_DEBUG_INFO, "plugins", "block aol system msg plugin loaded.\n");
	
	purple_signal_connect(conv_handle, "receiving-im-msg", plugin, PURPLE_CALLBACK(receiving_im_msg_cb), NULL);	

	return TRUE;
}

static gboolean
plugin_unload(PurplePlugin *plugin)
{
	purple_debug(PURPLE_DEBUG_INFO, "plugins", "block aol system msg plugin unloaded.\n");

	return TRUE;
}

static PurplePluginInfo info =
{
	PURPLE_PLUGIN_MAGIC,
	PURPLE_MAJOR_VERSION,
	PURPLE_MINOR_VERSION,
	PURPLE_PLUGIN_STANDARD,                           /**< type           */
	NULL,                                             /**< ui_requirement */
	0,                                                /**< flags          */
	NULL,                                             /**< dependencies   */
	PURPLE_PRIORITY_DEFAULT,                          /**< priority       */

	SIMPLE_PLUGIN_ID,                                 /**< id             */
	N_("Block AOL System Msg"),                		  /**< name           */
	"1.0",                                  		/**< version        */
	                                                  /**  summary        */
	N_("Blocks IM windows received from 'AOL System Msg'."),
	                                                  /**  description    */
	N_("Blocks IM windows received from 'AOL System Msg'."),
	"Chris Oakman <chris@oakmac.com>",        /**< author         */
	"",                                     /**< homepage       */

	plugin_load,                                      /**< load           */
	plugin_unload,                                    /**< unload         */
	NULL,                                             /**< destroy        */

	NULL,                                             /**< ui_info        */
	NULL,                                             /**< extra_info     */
	NULL,
	NULL,
	/* Padding */
	NULL,
	NULL,
	NULL,
	NULL
};

static void
init_plugin(PurplePlugin *plugin)
{
}

PURPLE_INIT_PLUGIN(simple, init_plugin, info)