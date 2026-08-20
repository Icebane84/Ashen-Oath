// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AshenAnimNotifyState_SlashVFX.generated.h"

/**
 * UAshenAnimNotifyState_SlashVFX
 *
 * AnimNotifyState attached to melee attack animation montages.
 * Spawns pooled Niagara blade trail VFX via UAshenVFXPoolSubsystem during the swing window.
 */
UCLASS()
class ASHENOATH_API UAshenAnimNotifyState_SlashVFX : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UAshenAnimNotifyState_SlashVFX();

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|VFX")
	FName TrailVFXName = FName("VFX_OathbringerSlashTrail");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|VFX")
	FName SocketName = FName("FX_BladeTip");
};
