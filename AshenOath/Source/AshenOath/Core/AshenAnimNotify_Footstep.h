// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AshenAnimNotify_Footstep.generated.h"

class USoundBase;

/**
 * UAshenAnimNotify_Footstep
 * Custom AnimNotify triggered when a foot contacts the ground during walking/running animations.
 * Raycasts down from the foot bone/socket to detect surfaces and plays dynamic footstep audio.
 */
UCLASS(const, hidecategories=Object, CollapseCategories, meta=(DisplayName="Ashen Footstep"))
class ASHENOATH_API UAshenAnimNotify_Footstep : public UAnimNotify
{
	GENERATED_BODY()

public:
	UAshenAnimNotify_Footstep();

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (AllowPrivateAccess = "true"))
	FName FootSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (AllowPrivateAccess = "true"))
	float TraceRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (AllowPrivateAccess = "true"))
	USoundBase* FootstepSound;
};
