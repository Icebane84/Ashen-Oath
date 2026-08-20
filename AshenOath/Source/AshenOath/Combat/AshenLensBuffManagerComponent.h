// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensBuffManagerComponent.generated.h"

/**
 * UAshenLensBuffManagerComponent
 * Manages tactical gameplay buffs granted by active lens (Utility threat perception +0.3, Grace stamina regen, Accountability poise).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensBuffManagerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensBuffManagerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Lenses")
	float ThreatPerceptionModifier = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Lenses")
	float PoiseBonus = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	void ApplyLensGameplayBuffs(EInterpretiveLens Lens);
};
