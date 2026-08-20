// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireJournalRestLocusActor.generated.h"

/**
 * AAshenCampfireJournalRestLocusActor
 * Interactive Heartstone campfire rest locus actor initiating journal entry compilation and companion marginalia discussions.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireJournalRestLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireJournalRestLocusActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire Rest")
	float IntrospectionRadius = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire Rest")
	bool bCampfireRestActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire Rest")
	bool InitiateCampfireJournalRest(AActor* InstigatorActor);
};
