// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenTripartiteResourceEconomyComponent.generated.h"

/**
 * UAshenTripartiteResourceEconomyComponent
 * Manages real-time resource transactions for the trio: Kaelen's input friction, Serafina's empathic burnout, and Garrett's sanity posture.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTripartiteResourceEconomyComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTripartiteResourceEconomyComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Economy")
	FTripartiteResourceState CurrentState;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Economy")
	void ApplyGlassShieldOverextension(float DamageAbsorbed);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Economy")
	void ApplyTransferenceHealing(float HealthMended);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Economy")
	void ApplySentinelPostureLoss(float PostureDamage);
};
