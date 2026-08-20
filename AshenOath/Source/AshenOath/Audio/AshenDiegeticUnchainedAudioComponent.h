// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticUnchainedAudioComponent.generated.h"

/**
 * UAshenDiegeticUnchainedAudioComponent
 * Plays guttural void roars, sun-pulse audio cracks, and frantic companion telemetry warnings.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticUnchainedAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticUnchainedAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayUnchainedRoar();
};
