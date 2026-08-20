// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * Centralized strongly-typed socket name constants for character models, weapons, and particle anchors.
 * Prevents string typos across C++, Blueprints, and Animation Events.
 */
namespace AshenSockets
{
	/** Left eye cornea anchor for crimson rim-lit particle emitters */
	static const FName Eyes_L = TEXT("SOCKET_Eyes_L");

	/** Right eye cornea anchor for crimson rim-lit particle emitters */
	static const FName Eyes_R = TEXT("SOCKET_Eyes_R");

	/** Chest emblem anchor for White Flame starburst light bursts */
	static const FName Emblem = TEXT("SOCKET_Emblem");

	/** Left forearm anchor for writhing shadow corruption vein emitters */
	static const FName ShadowMark_LeftForearm = TEXT("SOCKET_ShadowMark_LeftForearm");

	/** Oathbringer fuller channel anchor for blazing crimson embers */
	static const FName BladeSeam = TEXT("SOCKET_BladeSeam");

	/** Serafina collarbone anchor for silver locket light particles */
	static const FName Locket = TEXT("SOCKET_Locket");

	/** Garrett gauntlet anchor for wrist-grapple cable traces */
	static const FName Wrist_Grapple = TEXT("SOCKET_Wrist_Grapple");

	/** Right hand socket for main-hand weapon attachment */
	static const FName Hand_R = TEXT("Hand_R");
}
