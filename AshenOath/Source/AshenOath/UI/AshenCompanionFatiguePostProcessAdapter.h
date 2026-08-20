// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionFatiguePostProcessAdapter.generated.h"

/**
 * UAshenCompanionFatiguePostProcessAdapter
 * Manages post-process vignette pulse during heavy fatigue and golden lens bloom during Resonance Sync.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFatiguePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionFatiguePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyResonanceGlow(bool bActive);
};
