// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenMemoryEchoMindscapeCrucibleActor.generated.h"

/**
 * AAshenMemoryEchoMindscapeCrucibleActor
 * 3D world sanctuary crucible actor allowing Kaelen to enter Oathbringer's internal mindscape and confront symbolic memory echoes.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryEchoMindscapeCrucibleActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryEchoMindscapeCrucibleActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Meaning")
	bool bIsMindscapeCrucibleActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Meaning")
	void OpenMemoryEchoMindscape(FName MemoryID);
};
