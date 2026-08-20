// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSacredZoneReactionLocusActor.generated.h"

/**
 * AAshenSacredZoneReactionLocusActor
 * Locus actor triggering sacred zone sanctuary dialogues.
 */
UCLASS()
class ASHENOATH_API AAshenSacredZoneReactionLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSacredZoneReactionLocusActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void TriggerSacredZoneSanctuaryDialogue();
};
