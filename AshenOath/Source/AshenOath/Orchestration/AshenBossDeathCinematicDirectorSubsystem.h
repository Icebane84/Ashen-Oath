// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenBossDeathCinematicDirectorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossDeathCinematicTriggeredSignature, AActor*, BossActor, float, DilationDilationFactor);

/**
 * UAshenBossDeathCinematicDirectorSubsystem
 *
 * World Subsystem handling camera slow-motion and cinematic focus during boss deaths.
 */
UCLASS()
class ASHENOATH_API UAshenBossDeathCinematicDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossCinematic")
	void TriggerBossDeathCinematic(AActor* BossActor, float TimeDilation = 0.1f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossCinematic|Events")
	FOnBossDeathCinematicTriggeredSignature OnBossDeathCinematic;
};
