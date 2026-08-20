// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticVeilPhaseFilterComponent.generated.h"

/**
 * UAshenSomaticVeilPhaseFilterComponent
 * Actor Component scaling character somatic veil phase distortion resistance and physical mitigation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticVeilPhaseFilterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticVeilPhaseFilterComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Veil Phase")
	float VeilPhaseFilterResistance = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Veil Phase")
	void ApplyVeilPhaseFilterDamage(float Amount);
};
