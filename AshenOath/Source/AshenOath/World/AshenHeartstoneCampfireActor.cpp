// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenHeartstoneCampfireActor.h"
#include "World/AshenSanctuaryHeartstoneCrucibleComponent.h"
#include "Orchestration/AshenSLMCompilerSubsystem.h"
#include "Engine/GameInstance.h"

AAshenHeartstoneCampfireActor::AAshenHeartstoneCampfireActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CrucibleComponent = CreateDefaultSubobject<UAshenSanctuaryHeartstoneCrucibleComponent>(TEXT("CrucibleComponent"));
}

void AAshenHeartstoneCampfireActor::BeginPlay()
{
	Super::BeginPlay();

	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSLMCompilerSubsystem* Compiler = GI->GetSubsystem<UAshenSLMCompilerSubsystem>())
		{
			Compiler->OnCompilationCompleted.AddDynamic(this, &AAshenHeartstoneCampfireActor::OnCompilationCompleted);
		}
	}
}

void AAshenHeartstoneCampfireActor::ExecuteCampfireRest()
{
	if (!CrucibleComponent) return;

	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSLMCompilerSubsystem* Compiler = GI->GetSubsystem<UAshenSLMCompilerSubsystem>())
		{
			// 1. Gather Telemetry JSON
			FString PayloadJSON = CrucibleComponent->GenerateTelemetryPayload(Compiler->GetCurrentSoulState());

			// 2. Extract immutable memory IDs
			TArray<FString> ValidIDs = CrucibleComponent->GetPendingMemoryIDs();

			// 3. Initiate async SLM Compilation bridge
			UE_LOG(LogTemp, Warning, TEXT("AAshenHeartstoneCampfireActor: Executing Campfire Rest. Telemetry payload dispatched."));
			Compiler->RequestIdentityCompilation(PayloadJSON, ValidIDs);
		}
	}
}

void AAshenHeartstoneCampfireActor::OnCompilationCompleted(bool bSuccess, const FSoulStateVector& UpdatedVector)
{
	if (bSuccess && CrucibleComponent)
	{
		// 4. Secure Buffer Wipe upon verified firewall execution
		CrucibleComponent->FlushCompiledMemories();
		UE_LOG(LogTemp, Warning, TEXT("AAshenHeartstoneCampfireActor: Rest sequence complete! Soul State Corruption: %.2f | Resolve: %.2f"),
			UpdatedVector.Corruption, UpdatedVector.Resolve);
	}
}
