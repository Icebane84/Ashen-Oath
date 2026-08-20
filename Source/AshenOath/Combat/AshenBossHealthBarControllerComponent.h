// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossHealthBarControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnBossHealthBarUpdatedSignature, float, HealthPct, int32, PhaseIndex, FName, BossName);

/**
 * UAshenBossHealthBarControllerComponent
 *
 * Attached to boss actors. Manages multi-phase health bars and phase change notifications to HUD widgets.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossHealthBarControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossHealthBarControllerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossHUD")
	void UpdateBossHealth(float CurrentHealth, float MaxHealth, int32 CurrentPhase);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|BossHUD")
	FName BossDisplayName = FName("Greywatch Shroud-Knight");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossHUD|Events")
	FOnBossHealthBarUpdatedSignature OnBossHealthBarUpdated;
};
