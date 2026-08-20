// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticBossInquisitionAudioComponent.generated.h"

/**
 * UAshenDiegeticBossInquisitionAudioComponent
 * Latin choral chants, heavy cathedral bell tolls, radiant scripture bursts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBossInquisitionAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticBossInquisitionAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPhaseChoralTransition(uint8 PhaseEnum);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayInquisitionBellToll();
};
