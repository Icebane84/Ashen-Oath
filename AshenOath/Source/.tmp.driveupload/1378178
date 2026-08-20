// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenWeaponActor.h"
#include "AshenWeapon_Oathbringer.generated.h"

class UPointLightComponent;
class UMaterialInstanceDynamic;

/**
 * AAshenWeapon_Oathbringer
 * Sentient weapon that dynamically scales its mesh size, adjusts emission glow parameters,
 * and alters its point light color and pulse rate based on its wielder's corruption level.
 */
UCLASS()
class ASHENOATH_API AAshenWeapon_Oathbringer : public AAshenWeaponActor
{
	GENERATED_BODY()

public:
	AAshenWeapon_Oathbringer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPointLightComponent* EmissionLight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	FLinearColor PureColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	FLinearColor CorruptColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	float CorruptionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	float MaxScaleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	FName GlowColorParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Oathbringer|Visuals")
	FName GlowIntensityParamName;

private:
	UPROPERTY()
	UMaterialInstanceDynamic* WeaponMID;

	FVector BaseScale;
	float CurrentCorruption;
};
