// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensSanctuaryPillarActor.generated.h"

/**
 * AAshenLensSanctuaryPillarActor
 * Tripartite Mindscape pillar actor in Consecrated Sanctuaries allowing Kaelen to commune and choose an Interpretive Lens.
 */
UCLASS()
class ASHENOATH_API AAshenLensSanctuaryPillarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLensSanctuaryPillarActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Lenses")
	EInterpretiveLens PillarLens = EInterpretiveLens::Grace;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Lenses")
	bool bIsPillarActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lenses")
	bool CommuneWithPillar(AActor* InteractingPlayer);
};
