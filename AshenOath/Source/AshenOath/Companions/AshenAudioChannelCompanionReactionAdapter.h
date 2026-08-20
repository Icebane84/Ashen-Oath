// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenAudioChannelCompanionReactionAdapter.generated.h"

/**
 * UAshenAudioChannelCompanionReactionAdapter
 * Modulates companion head-turn tracking and eye contact when addressing Kaelen through his personal action channel.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAudioChannelCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAudioChannelCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void OrientCompanionToPersonalChannel(FName CompanionID);
};
