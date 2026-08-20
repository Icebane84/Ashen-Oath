// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicMemoryAnchorActor.generated.h"

/**
 * AAshenEpistemicMemoryAnchorActor
 * 3D world monument physically anchored at boss resolution sites displaying the memory constellation conduit.
 */
UCLASS()
class ASHENOATH_API AAshenEpistemicMemoryAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenEpistemicMemoryAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	FName AnchoredEncounterID = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsAnchorActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void EstablishAnchor(FName EncounterID, bool bIsSynarchy);
};
