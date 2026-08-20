// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPhysicalJournalPedestalActor.generated.h"

/**
 * AAshenPhysicalJournalPedestalActor
 * 3D world interactive lectern/pedestal where the living journal can be laid flat for high-resolution celestial map inspection.
 */
UCLASS()
class ASHENOATH_API AAshenPhysicalJournalPedestalActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenPhysicalJournalPedestalActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	bool bIsJournalPlaced = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	void PlaceJournalOnPedestal(bool bPlaced);
};
