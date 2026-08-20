// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenCartographerMemoryConstellationActor.generated.h"

/**
 * AAshenCartographerMemoryConstellationActor
 * 3D world map actor rendering glowing Gold-White Ley Conduits vs jagged Obsidian Fractures across regional sectors.
 */
UCLASS()
class ASHENOATH_API AAshenCartographerMemoryConstellationActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCartographerMemoryConstellationActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Map")
	EConstellationNodeVisual CurrentNodeVisual = EConstellationNodeVisual::Unresolved;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map")
	void InscribeSectorResolution(EJournalPerspectiveType Perspective);
};
