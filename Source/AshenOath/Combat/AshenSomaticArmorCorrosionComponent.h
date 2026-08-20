// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticArmorCorrosionComponent.generated.h"

/**
 * UAshenSomaticArmorCorrosionComponent
 * Actor Component scaling character armor corrosion material scuffs and physical defense mitigation based on SoulState corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticArmorCorrosionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticArmorCorrosionComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Armor")
	float ArmorCorrosionLevel = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Armor")
	void ApplyArmorCorrosionDamage(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Armor")
	float GetCorrosionMitigationScalar() const;
};
