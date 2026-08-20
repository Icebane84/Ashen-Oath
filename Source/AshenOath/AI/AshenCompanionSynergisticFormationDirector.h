// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionSynergisticFormationDirector.generated.h"

/**
 * UAshenCompanionSynergisticFormationDirector
 * AI Director component orchestrating 3-character companion synergistic tactical formation positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionSynergisticFormationDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionSynergisticFormationDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bSynergisticFormationActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizeSynergisticFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
