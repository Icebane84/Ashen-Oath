// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenDiegeticBestiaryFinisherAudioComponent.generated.h"

/**
 * UAshenDiegeticBestiaryFinisherAudioComponent
 * Manages bespoke audio stingers: glass shatter for Echo-Maimer, thermal quench hiss for Slag-Serpent/Ash-Casket, and obsidian crystal fracture.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBestiaryFinisherAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticBestiaryFinisherAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayBestiaryAudioStinger(EAshenPartyFinisherType FinisherType);
};
