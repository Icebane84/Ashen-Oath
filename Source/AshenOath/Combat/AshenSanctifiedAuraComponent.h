// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctifiedAuraComponent.generated.h"

/**
 * UAshenSanctifiedAuraComponent
 * Evaluates radial holy-kinetic aura (600.0uu radius), cleansing negative status effects and providing a 20% stamina recovery buff.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctifiedAuraComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSanctifiedAuraComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float AuraRadiusUnits = 600.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float StaminaBuffMultiplier = 1.20f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	void CleanseNegativeStatusEffects();
};
