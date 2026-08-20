// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenDiegeticFinisherAudioComponent.generated.h"

/**
 * UAshenDiegeticFinisherAudioComponent
 * Manages resonant steel chimes, alchemical ignition whooshes, and empathic detonation sonic shockwaves.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticFinisherAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticFinisherAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayFinisherAudioStinger(EAshenPartyFinisherType FinisherType);
};
