# Backend Sync Subsystem (Ashen Oath)

This document describes the `UAshenBackendSyncSubsystem` backend persistence and imprint emission features added to Ashen Oath.

## Summary of Changes

- New subsystem: `UAshenBackendSyncSubsystem` implemented in `Source/AshenOath/AshenBackendSyncSubsystem.*`.
- The subsystem subscribes to `UAshenSoulConstellationSubsystem::OnStateVectorInvalidated` and sends canonical `FSoulStateVector` payloads to a configured HTTP endpoint.
- Consumed `FPsychologicalImprint` arrays are emitted via `EmitImprintsAsync()` from `FinalizeIntegration()`.
- Failed HTTP payloads are persisted under `Saved/BackendSyncCache/*.json` and retried periodically.
- `UAshenSaveManager::SaveGameData` triggers `ForceSyncCurrentState()` after successful local save.

## Files

- Source: `Source/AshenOath/AshenBackendSyncSubsystem.h`
- Source: `Source/AshenOath/AshenBackendSyncSubsystem.cpp`
- Test: `Source/AshenOath/QA/BackendSyncTests.cpp`
- Config: `Config/DefaultGame.ini` (section `/Script/AshenOath.AshenBackendSyncSubsystem`)

## Configuration (DefaultGame.ini)

Add or edit the following section in `Config/DefaultGame.ini` to configure the endpoint and auth header:

[/Script/AshenOath.AshenBackendSyncSubsystem]
; Enable automatic sync on each published state vector
bAutoSyncOnPublish=true

; Remote backend endpoint to receive state vector JSON POSTs
BackendEndpoint="https://your-backend.example.com/api/ashen/state/sync"

; Optional Authorization header (use project secrets management in production)
AuthorizationHeader="Bearer <REPLACE_WITH_SECRET>"

## Runtime Behavior

- On every `PublishStateVector()` the subsystem attempts a POST of the serialized `FSoulStateVector` as JSON.
- On every `FinalizeIntegration()` consumed imprints are serialized and sent via `EmitImprintsAsync()`.
- If a POST fails or dispatch fails, payloads are written to `Saved/BackendSyncCache` and retried with exponential backoff.
- Retry payloads are discarded after `MaxRetryAttempts` (default 5).
- Retry timing is controlled by `BaseRetryIntervalSeconds` and `RetryBackoffMultiplier` in `UAshenBackendSyncSubsystem` config.
- Lookup and manage the retry cache from the editor console with `AshenBackendSync.InspectRetryCache` and `AshenBackendSync.FlushRetryCache`.

## Editor Console Commands

Use these commands in the editor/Pie console:

- `AshenBackendSync.InspectRetryCache`
- `AshenBackendSync.FlushRetryCache`

## How to Run the Tests

Run the automation test in-editor (Session Frontend -> Automation) or via command line:

```powershell
"C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UE4Editor-Cmd.exe" "C:\path\to\AshenOath.uproject" -run=AutomationTests -Test="AshenOath.Backend.ImprintSerialization"
```

Note: adjust the editor executable path for UE 5.8 as appropriate.

## Next Steps and Recommendations

- Replace auth token in `DefaultGame.ini` with secure secret store or platform-specific vault.
- Improve retry logic with exponential backoff and max attempt counts.
- Add an editor command to flush/inspect `Saved/BackendSyncCache`.
- Add integration tests covering end-to-end HTTP success/failure (requires test server or mock server).

