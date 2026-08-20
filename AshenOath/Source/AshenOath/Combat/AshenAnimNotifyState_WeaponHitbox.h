// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AshenAnimNotifyState_WeaponHitbox.generated.h"

/**
 * UAshenAnimNotifyState_WeaponHitbox
 * AnimNotifyState used in attack montages to activate the equipped weapon's hitbox.
 * Automatically queries character interface to obtain the weapon actor instance.
 */
UCLASS(hidecategories=Object, CollapseCategories, meta=(DisplayName="Ashen Weapon Hitbox State"))
class ASHENOATH_API UAshenAnimNotifyState_WeaponHitbox : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
