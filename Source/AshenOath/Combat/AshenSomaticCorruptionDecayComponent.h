// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticCorruptionDecayComponent.generated.h"

/**
 * UAshenSomaticCorruptionDecayComponent
 * Actor Component scaling character stamina and poise decay under persistent corruption accumulation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticCorruptionDecayComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticCorruptionDecayComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Decay")
	float AccumulatedCorruptionLevel = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Decay")
	float StaminaDecayMultiplier = 1.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Decay")
	void AccumulateSomaticCorruption(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Decay")
	float GetEffectivePoiseDecayMultiplier() const;
};
