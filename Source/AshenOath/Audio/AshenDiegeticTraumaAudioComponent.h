// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenDiegeticTraumaAudioComponent.generated.h"

/**
 * UAshenDiegeticTraumaAudioComponent
 * Manages spatial audio cues for Whispering Winds (Memory Bleed), heartbeat friction throbs, and forced mindscape alarms.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTraumaAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticTraumaAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateDebtAudioState(EIntegrationDebtStage Stage);
};
