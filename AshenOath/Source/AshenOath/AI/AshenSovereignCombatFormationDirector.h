// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSovereignCombatFormationDirector.generated.h"

/**
 * UAshenSovereignCombatFormationDirector
 * AI Director component orchestrating the Sovereign Phoenix 3-character tactical combat formation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSovereignCombatFormationDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSovereignCombatFormationDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bSovereignFormationSynchronized = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizeSovereignFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
