// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireWorkstationActor.generated.h"

/**
 * AAshenCampfireWorkstationActor
 * Interactive campfire world actor that deploys Garrett's portable alchemical crafting workstation and allows party rest.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireWorkstationActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCampfireWorkstationActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire")
	float RestRadius = 500.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Campfire")
	bool bIsCampfireLit = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	bool InteractWithWorkstation(AActor* InstigatingPlayer);
};
