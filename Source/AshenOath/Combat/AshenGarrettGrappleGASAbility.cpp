// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenGarrettGrappleGASAbility.h"

UAshenGarrettGrappleGASAbility::UAshenGarrettGrappleGASAbility() {}

bool UAshenGarrettGrappleGASAbility::ActivateGarrettGrapple(FVector TargetPos)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettGrappleGASAbility: Grapple ability activated targeting (%f, %f, %f)!"), TargetPos.X, TargetPos.Y, TargetPos.Z);
	return true;
}
